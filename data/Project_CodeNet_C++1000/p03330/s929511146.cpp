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
    int N, C;
    cin >> N >> C;

    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C)rep(j, C) cin >> D[i][j];

    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N)rep(j, N) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<vector<int>> cnt(3, vector<int>(C));
    rep(i, N)rep(j, N) {
        int g = (i + j) % 3;
        int c = A[i][j];
        cnt[g][c]++;
    }

    int ans = INF;
    rep(i, C) {
        rep(j, C) {
            rep(k, C) {
                if (i == j || i == k || j == k) continue;
                int res = 0;
                rep(c, C) {
                    res += cnt[0][c] * D[c][i];
                    res += cnt[1][c] * D[c][j];
                    res += cnt[2][c] * D[c][k];
                }
                chmin(ans, res);
            }
        }
    }

    cout << ans << endl;
}