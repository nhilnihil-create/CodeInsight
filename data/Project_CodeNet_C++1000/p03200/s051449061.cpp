#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0, b = 0;
    rep(i, n)
    {
        if (s[i] == 'B')
            b++;
        else
            ans += b;
    }
    cout << ans << endl;
}