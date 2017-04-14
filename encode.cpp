#include <iostream>
#include <string>
using namespace std;

/*
使い方
配列fugouにA,B,C,Dの順に、符号化した文字列を入れます。
コンパイルします。
実行します。
符号化したい文字列を入力します。
復号化されたときの候補が出力されます。
*/

string fugou[4] = {"0","01","011","111"};

//strには調べる文字列が入る
//decodedには今まで解読してきた文字列が入る
void run(string str,string decoded){

    if(str.length() == 0){
        cout << decoded << endl;
        return;
    }
    for(int i = 0; i < 4; i++){
        if( str.length() >= fugou[i].length() && str.substr(0,fugou[i].length()) == fugou[i]){
            string tmp = decoded;
            tmp += ('A' + i);
            run( str.substr(fugou[i].length()),tmp);
        }
    }
    return;
}

string encode(string str){
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        ans += fugou[str[i] - 'A'];
    }
    return ans;
}

int main() {
    string str;
    cin >> str;

    run(encode(str),"");
    return 0;
}
