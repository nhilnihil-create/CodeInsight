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

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> cs(N);  // [0, i] の和
    REP(i, N) {
        cin >> A[i];
        if(i == 0) {
            cs[i] = A[i];
        }
        else {
            cs[i] = cs[i-1] + A[i];
        }
    }

    int ans = 0;
    map<int, int> cnt;  // 自分より右の値が key の個数
    for(int i = N - 1; i >= 0; --i) {
        int val = cs[i] - A[i];
        if(cnt.count(val) > 0) {
            ans += cnt[val];
        }
        if(A[i] == 0) { ans++; }
        cnt[cs[i]]++;
    }
    printf("%lld\n", ans);

    return 0;
}

