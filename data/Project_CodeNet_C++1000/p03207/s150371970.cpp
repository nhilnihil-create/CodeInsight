#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int ans = 0, mx = 0;
    rep(i, n)
    {
        ans += p[i];
        mx = max(mx, p[i]);
    }
    ans -= mx / 2;
    cout << ans << endl;
    return 0;
}