#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <numeric>
#include <iomanip>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin>>N;
    vector<double> ts(N), vs(N);
    for (ll n = 0; n < N; n++) cin>>ts[n];
    for (ll n = 0; n < N; n++) cin>>vs[n];

    double T = accumulate(begin(ts), end(ts), 0.0);
    vector<double> v(2*T+1);
    for (ll t = 0; t <= 2*T; t++) v[t] = min(0.5*t, T-0.5*t);

    double t_begin = 0;
    for (ll n = 0; n < N; n++) {
        for (ll t = 0; t <= 2*T; t++) {
            double new_v;
            if (0.5 * t < t_begin) new_v = (t_begin - 0.5 * t) + vs[n];
            else if (0.5 * t < t_begin + ts[n]) new_v = vs[n];
            else new_v = (0.5 * t - t_begin - ts[n]) + vs[n];

            v[t] = min(v[t], new_v);
        }
        t_begin += ts[n];
    }
    double ans = 0.0;
    for (ll t = 0; t < 2*T; t++) ans += 0.5 * (v[t] + v[t+1]) / 2.0;
    cout<<setprecision(8)<<ans<<endl;

    return 0;
}