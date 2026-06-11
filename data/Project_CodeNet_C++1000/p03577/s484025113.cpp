#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string ans = "";
    int n = s.length();
    for(int i = 8;i < n; i++){
        ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}