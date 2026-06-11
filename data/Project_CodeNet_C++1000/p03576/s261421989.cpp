#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, K;
vector<pll> v;
ll M[100];

signed main(){
    cin >> N >> K;
    ll x, y;
    REP(i, N){
        cin >> x >> y;
        v.push_back(pll(x, y));
    }
    REP(i, N + 1) M[i] = LONG_LONG_MAX;
    sort(ALL(v));
    REP(k, N - 1){
        FOR(l, k + 1, N){
            ll y_min = min(v[k].second, v[l].second);
            ll y_max = max(v[k].second, v[l].second);
            ll sum = 0;
            REP(i, N){
                ll sum = 0;
                ll x_l = v[i].first;
                FOR(j, i, N){
                    ll x = v[j].first, y = v[j].second;
                    if(y_min <= y && y <= y_max){
                        sum++;
                        M[sum] = min(M[sum], (y_max - y_min) * (x - x_l));
                    }
                }
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    FOR(i, K, N + 1) ans = min(ans, M[i]);
    PRINT(ans);
    return 0;
}