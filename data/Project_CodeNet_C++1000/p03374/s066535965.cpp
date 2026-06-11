#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

ll N, C;

ll solve(vector<ll> &x, vector<ll> &v){
    vector<ll> f(100100), mf(100100), g(100100);
    f[0] = 0;
    ll v_sum = 0;
    REP(i, N){
        v_sum += v[i];
        f[i+1] = v_sum - x[i];
    }
    ll tmp_max = -1;
    REP(i, N+1){
        tmp_max = max(tmp_max, f[i]);
        mf[i] = tmp_max;
    }
    g[0] = 0;
    ll v_sum2 = 0;
    REP(i, N+1){
        v_sum2 += v[N-1-i];
        g[i+1] = v_sum2 - 2*(C-x[N-1-i]);
    }
    ll res = -1;
    REP(i, N+1){
        res = max(res, mf[i] + g[N-i]);
    }

    return res;
}

int main(){
    cin >> N >> C;
    vector<ll> x(100100), v(1000100), xr(100100), vr(100100);
    REP(i, N) cin >> x[i] >> v[i];
    REP(i, N){
        xr[i] = C - x[N-1-i];
        vr[i] = v[N-1-i];
    }
    cout << max(solve(x, v), solve(xr, vr)) << endl;
    return 0;
}