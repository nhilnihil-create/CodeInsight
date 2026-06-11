#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    rep(i, a) cin >> s[i+1];
    rep(i, b) cin >> t[i+1];
    s[0] = -inf;
    t[0] = -inf;
    s[a + 1] = inf;
    t[b + 1] = inf;
    rep(i, q)
    {
        ll x;
        cin >> x;
        int si = lower_bound(s.begin(), s.end(), x) - s.begin();
        int ti = lower_bound(t.begin(), t.end(), x) - t.begin();
        ll tmp1 = max(s[si] - x, t[ti] - x);
        ll tmp2 = max(x - s[si - 1], x - t[ti-1]);
        ll tmp3 = s[si] - t[ti - 1] + min(s[si] - x, x - t[ti - 1]);
        ll tmp4 = t[ti] - s[si - 1] + min(t[ti] - x, x - s[si - 1]);
        ll tmpans = min({tmp1, tmp2, tmp3, tmp4});
        cout << tmpans << "\n";
    }
    return 0;
}
