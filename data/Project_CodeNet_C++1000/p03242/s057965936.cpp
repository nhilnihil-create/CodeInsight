#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    rep(i,3){
        if(s[i] == '1') cout << '9';
        else cout << '1';
    }
    cout << endl;
    return 0;
}