#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int num = 753;
    int ans = 1e9;
    rep(i, n - 2)
    {
        int x = 0;
        rep(j, 3)
        {
            x *= 10;
            x += s[i + j] - '0';
        }
        ans = min(ans, abs(num - x));
    }
    cout << ans << endl;
    return 0;
}