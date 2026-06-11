#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());
    if(s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}