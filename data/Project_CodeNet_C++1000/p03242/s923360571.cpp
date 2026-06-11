#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ

int main(void){
    string s;
    cin >> s;
    if(s[0] == '1'){
        s[0] = '9';
    }else if(s[0] == '9'){
        s[0] = '1';
    }
    if(s[1] == '1'){
        s[1] = '9';
    }else if(s[1] == '9'){
        s[1] = '1';
    }
    if(s[2] == '1'){
        s[2] = '9';
    }else if(s[2] == '9'){
        s[2] = '1';
    }
    cout << s << endl;
}