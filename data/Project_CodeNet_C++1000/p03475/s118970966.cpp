#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
const int MAX_N = 100010;

int N;
vector<int> C, S, F;

int dfs(int i, int t) {
    //DBG("i: %lld t: %lld\n", i, t);
    if(i >= N - 1) { return 0; }

    int ret = 0;
    //DBG("C: %lld S: %lld F: %lld\n", C[i], S[i], F[i]);
    if(t <= S[i]) {
        int diff = S[i] - t;
        ret += dfs(i + 1, S[i] + C[i]) + diff + C[i];
    }
    else {
        int diff = F[i] - (t % F[i]);
        if(t % F[i] == 0) { diff = 0; }
        ret = dfs(i + 1, t + diff + C[i]) + diff + C[i];
    }
    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    C.resize(N-1);
    S.resize(N-1);
    F.resize(N-1);
    REP(i, N-1) {
        cin >> C[i] >> S[i] >> F[i];
    }

    REP(i, N) {
        int ans = dfs(i, 0);
        printf("%lld\n", ans);
    }

    return 0;
}