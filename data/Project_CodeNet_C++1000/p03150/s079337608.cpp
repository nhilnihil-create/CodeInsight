#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string k = s;
    int n = s.length();
    string key = "keyence";
    rep(i,n){
        rep(j,n){
            if(s.erase(i,j) == key){
                cout << "YES" << endl;
                return 0;
            }
            s = k;
        }
    }
    cout << "NO" << endl;
    return 0;
}