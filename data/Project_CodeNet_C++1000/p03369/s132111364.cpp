#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,3){
        if(s[i] == 'o') cnt++;
    }
    cout << 700 + 100*cnt << endl;
    return 0;
}