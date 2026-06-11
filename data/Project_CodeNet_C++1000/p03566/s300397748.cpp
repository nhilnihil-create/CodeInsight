#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;

vll t, v;
ll N, T;

double f(double x, double l, double r, double c) {
    if (x < l) return c + (l - x);
    else if (x < r) return c;
    else return c + (x - r);
}

double calc_min(double x) {
    double minn = inf;
    minn = min(minn, f(x, 0, 0, 0));
    minn = min(minn, f(x, T, T, 0));
    ll atime = 0;
    rep(i, N) {
        minn = min(minn, f(x, atime, atime + t[i], v[i]));
        atime += t[i];
    }
    return minn;
}

int main()
{
    cin >> N;
    t.resize(N), v.resize(N);
    rep(i, N) cin >> t[i];
    rep(i, N) cin >> v[i];
    T = accumulate(all(t), 0LL);

    double time = 0;
    double distance = 0;
    while (time < T) {
        distance += 0.25 * (calc_min(time) + calc_min(time + 0.5));
        time += 0.5;
    }
    printf("%.12lf\n", distance);
    return 0;
}