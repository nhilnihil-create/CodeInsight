#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
//#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
signed main() {
    int N, M;
    cin >> N >> M;
    int V[N][3];
    rep(i, N) {
        rep(j, 3) cin >> V[i][j];
    }
    int ans = 0;
    rep(i, 8) {
        vector<int> V0;
        rep(j, N) {
            int sum = 0;
            rep(k, 3) {
                if((i >> k) & 1)
                    sum += V[j][k];
                else
                    sum -= V[j][k];
            }
            V0.push_back(sum);
        }
        sort(all(V0), greater<int>());
        int sum = 0;
        rep(j, M) sum += V0[j];
        chmax(ans, sum);
    }
    cout << ans << endl;
}
