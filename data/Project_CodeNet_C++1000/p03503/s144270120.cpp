#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
//typedef pair<int, int> P;
typedef tuple<string, int, int> T;

int N;
int F[110][15];
int P[110][15];

signed main() {
    cin >> N;
    rep(i, N) rep(j, 10) cin >> F[i][j];
    rep(i, N) rep(j, 11) cin >> P[i][j];
    int ans = -1000000000000;
    rep(S, 1<<10) {
        if (S==0) continue;
        int ans_cand = 0;
        rep(i, N) {
            int cnt = 0;
            rep(j, 10) {
                if (F[i][j]==1 && (S>>j)&1) cnt++;
            }
            ans_cand += P[i][cnt];
        }
        ans = max(ans, ans_cand);
    }
    cout << ans << endl;
}