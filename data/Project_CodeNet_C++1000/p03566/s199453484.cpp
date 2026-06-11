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
struct Condition
{
public:
    double l;
    double r;
    double v;
};
//------------------------------------------------------------------------------
void _main()
{
    int N;
    cin >> N;
    vector<double> t(N);
    vector<double> v(N);
    rep(i, 0, N) cin >> t[i];
    rep(i, 0, N) cin >> v[i];
    double T = 0.0;
    vector<Condition> conds;
    {
        conds.push_back({0, 0, 0});
        rep(i, 0, N)
        {
            conds.push_back({T, T + t[i], v[i]});
            T += t[i];
        }
        conds.push_back({T, T, 0});
    }
    double ans = 0.0;
    double time = 0.5;
    double vel = 0.0;
    while (true)
    {
        double v = 10000.0;
        for (const auto& cond : conds)
        {
            if (time <= cond.l)
            {
                chmin(v, cond.v + (cond.l - time));
            }
            else if(time >= cond.r)
            {
                chmin(v, cond.v + (time - cond.r));
            }
            else
            {
                chmin(v, cond.v);
            }
        }

        ans += (vel + v) * 0.5 * 0.5;

        if (time >= T) break;

        time += 0.5;
        vel = v;
    }
    cout << setprecision(15) << ans << endl;
}
