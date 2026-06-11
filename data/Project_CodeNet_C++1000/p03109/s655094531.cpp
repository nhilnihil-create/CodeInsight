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
    if((s[6] == '4' || s[6] =='1' && s[5] == '0' || s[6] == '2' && s[5] == '0' || s[6] == '3' )  && (s[8] == '0' || s[8] == '1' || s[8] == '2' || s[8] == '3')){
        cout << "Heisei" << endl;
    }else {
        cout << "TBD" << endl;
    }
}