#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void _main()
{
    int N;
    cin >> N;
    vector<double> t(N + 1);
    vector<double> v(N + 1);
    rep(i, 0, N) cin >> t[i];
    rep(i, 0, N) cin >> v[i];
    t[N] = v[N] = 0.0;
    rrep(i, N - 1, 0)
    {
        chmin(v[i], v[i + 1] + t[i]);
    }

    double ans = 0.0;
    double vel = 0.0;
    rep(i, 0, N)
    {
        const double x = (t[i] + (v[i + 1] - vel)) * 0.5;
//        assert(x >= 0.0);

        if (x <= t[i])
        {
            if ((vel + x) <= v[i])
            {
                ans += ((vel + (vel + x)) * x * 0.5) + (((vel + x) + v[i + 1]) * (t[i] - x) * 0.5);
                vel = v[i + 1];
            }
            else
            {
                if (v[i] > v[i + 1])
                {
                    const double t1 = v[i] - vel;
                    const double t2 = t[i] - (v[i] - v[i + 1]);
//                    assert(t1 >= 0.0 && t1 <= t[i]);
//                    assert(t2 >= 0.0 && t2 <= t[i]);
//                    assert(t2 >= t1);
                    ans += ((vel + v[i]) * t1 * 0.5) + (v[i] * (t2 - t1)) + ((v[i] + v[i + 1]) * (t[i] - t2) * 0.5);
                    vel = v[i + 1];
                }
                else
                {
                    const double t1 = v[i] - vel;
//                    assert(t1 >= 0.0 && t1 <= t[i]);
                    ans += ((vel + v[i]) * t1 * 0.5) + (v[i] * (t[i] - t1));
                    vel = v[i];
                }
            }
        }
        else
        {
            if ((vel + t[i]) <= v[i])
            {
                ans += (vel + (vel + t[i])) * t[i] * 0.5;
                vel = vel + t[i];
            }
            else
            {
                const double t1 = v[i] - vel;
//                assert(t1 >= 0.0 && t1 <= t[i]);
                ans += ((vel + v[i]) * t1 * 0.5) + (v[i] * (t[i] - t1));
                vel = v[i];
            }
        }
    }
    printf("%.15lf\n", ans);
}
