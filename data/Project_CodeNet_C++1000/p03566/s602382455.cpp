#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>
#include<bitset>

#define int long long
#define double long double
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
int T[110];
int V[110];

template<typename... Args>
void debug(Args... args) {
    for (auto arg:{args...})cerr << arg << " ";
    cerr << endl;
}

pair<double, int> f(int t, int v, int vf, int vm) {
    vf = min(vf, vm);
    if (v + t < vf) {
        double ans = (v + v + t) * t / 2.;
        return make_pair(ans, v + t);
    }

    double ka = 0, ge = 0;
    if (v > vf)ge = v - vf;
    else ka = vf - v;
    t -= ge + ka;
    ka += t / 2.;
    ge += t / 2.;
    double to = 0;
    if (v + ka > vm) {
        //v+ka=vm
        to = (v + ka - vm);
        ka -= to;
        ge -= to;
        to *= 2;
    }
    double ans = (v + v + ka) * ka / 2. + (v + ka) * to + (v + ka + vf) * ge / 2.;
    return make_pair(ans, vf);
}

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> T[i + 1];
    }
    rep(i, N) {
        cin >> V[i + 1];
    }
    for (int i = N; i >= 0; --i) {
        V[i] = min(V[i], V[i + 1] + T[i]);
    }
    double ans = 0;
    int v_prev = 0;
    for (int i = 0; i <= N; ++i) {
        auto p = f(T[i + 1], v_prev, V[i + 2], V[i + 1]);
        v_prev = p.second;
        ans += p.first;
    }
    printf("%.20Lf", ans);
    return 0;
}
