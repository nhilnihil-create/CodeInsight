#include <bits/stdc++.h>
#define INF 1e9
#define int long long
#define Rep(i, n, a) for (int i = a; i < n; i++)
#define Repr(i, n, a) for (int i = n; i >= a; i--)
#define rep(i, n) Rep(i, n, 0)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

int n;
vector<PP> vp;

double func(double t)
{
    double res = INF;
    rep(i, n + 2)
    {
        double tmp;
        if (t < vp[i].second.first)
            tmp = vp[i].first + vp[i].second.first - t;
        else if (vp[i].second.second < t)
            tmp = vp[i].first + t - vp[i].second.second;
        else
            tmp = vp[i].first;
        res = min(res, tmp);
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<double> t(n), v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    int T = 0;
    rep(i, n) T += t[i];
    vp.push_back(PP{0, P{0, 0}});
    vp.push_back(PP{0, P{T, T}});
    int sumt = 0;
    rep(i, n)
    {
        vp.push_back(PP{v[i], P{sumt, sumt + t[i]}});
        sumt += t[i];
    }
    double ans = 0;
    rep(i, 2 * T) ans += (func(i / 2.0) + func(i / 2.0 + 0.5)) * 0.25;
    printf("%10lf\n", ans);
}