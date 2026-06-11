#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;


int main(){
    string s;
    cin >> s;
    s = s + '/';
    int info[3];
    int count = 0;
    string sub = string();
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '/') sub += s[i];
        else{
            if(sub[0] == '0'){
                sub = sub.substr(1,sub.length()-1);
            }
            info[count] = stoi(sub);
            count++;
            sub = string();
        }
    }
    if(info[0] < 2019) cout << "Heisei" << endl;
    else if(info[0] > 2019) cout << "TBD" << endl;
    else if(info[1] > 4) cout << "TBD" << endl;
    else if(info[1] < 4) cout << "Heisei" << endl;
    else if(info[2] > 30) cout << "TBD" << endl;
    else cout << "Heisei" << endl;
    return 0;
}