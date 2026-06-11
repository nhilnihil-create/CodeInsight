#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> L(M), R(M);
    rep(i, M) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }

    vector<int> p(Q), q(Q);
    rep(i, Q) {
        cin >> p[i] >> q[i];
        p[i]--;
    }

    vector<vector<int>> v(N, vector<int>(N));
    rep(i, M) {
        v[L[i]][R[i]]++;
    }

    vector<vector<int>> sum(N+1, vector<int>(N+1));
    rep(i, N)rep(j, N) {
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + v[i][j];
    }

    rep(i, Q) {
        int ans = sum[q[i]][q[i]] - sum[p[i]][q[i]] - sum[q[i]][p[i]] + sum[p[i]][p[i]];
        cout << ans << endl;
    }
}