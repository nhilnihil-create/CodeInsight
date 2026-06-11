#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
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
#define MAX_N 100010

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    vector<int> V;
    cin >> N;
    V.resize(N);
    REP(i, N) {
        cin >> V[i];
    }

    // key: 数, val: 出現数
    map<int, int> even, odd;
    REP(i, N) {
        if(i % 2 == 0) {
            even[V[i]]++;
        }
        else {
            odd[V[i]]++;
        }
    }

    vector< pair<int, int> > v_even, v_odd;


    for(auto& tmp : even) {
        v_even.push_back(make_pair(tmp.second, tmp.first));
    }
    v_even.push_back(make_pair(0, -1));
    for(auto& tmp : odd) {
        v_odd.push_back(make_pair(tmp.second, tmp.first));
    }
    v_odd.push_back(make_pair(0, -1));
    SORT(v_even);
    reverse(v_even.begin(), v_even.end());
    SORT(v_odd);
    reverse(v_odd.begin(), v_odd.end());

    int ans = N;

    int i_n = v_even.size();
    if(i_n > 10) { i_n = 10;}
    int j_n = v_odd.size();
    if(j_n > 10) { j_n = 10;}
    for(int i = 0; i < i_n; ++i) {
        for(int j = 0; j < j_n; ++j) {
            if(v_even[i].second != v_odd[j].second) {
                ans = min(ans, N - v_even[i].first - v_odd[j].first);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
