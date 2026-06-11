#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define REP(i, n) FOR(i, 1, ll(n) + 1)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int N, K, Q;
vector<int> A;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K >> Q;
    A.resize(N);
    rep(i, N) cin >> A[i];

    int ret = 1 << 30;
    rep(i, N) {
        vector<int> P, V;
        rep(j, N) {
            if(A[j] < A[i]) {
                if(V.size() >= K) {
                    sort(ALL(V));
                    rep(x, V.size() - K + 1) P.push_back(V[x]);
                }
                V.clear();
            } else
                V.push_back(A[j]);
        }
        if(V.size() >= K) {
            sort(ALL(V));
            rep(x, V.size() - K + 1) P.push_back(V[x]);
        }
        if(P.size() < Q) continue;
        sort(ALL(P));
        chmin(ret, P[Q - 1] - P[0]);
    }

    cout << ret << endl;

    return 0;
}