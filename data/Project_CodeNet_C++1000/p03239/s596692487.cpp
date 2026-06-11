#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, T;
    cin >> n >> T;
    int ans = 1e9;
    rep(i, n)
    {
        int c, t;
        cin >> c >> t;
        if (t <= T)
            ans = min(ans, c);
    }
    if (ans != 1e9)
        cout << ans << endl;
    else
        cout << "TLE" << endl;
    return 0;
}