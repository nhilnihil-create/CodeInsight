#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int ans = 0, n = s.length();
    rep(i, n)
    {
        if (s[i] == 'o')
            ans++;
    }
    ans += 15 - n;
    if (ans >= 8)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
