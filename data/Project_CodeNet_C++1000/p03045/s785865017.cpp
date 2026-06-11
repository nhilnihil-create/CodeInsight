#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

#define NIL -1

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    int X, Y, Z;
    rep(i, M) {
        cin >> X >> Y >> Z;
        X--; Y--;
        G[X].push_back(Y); G[Y].push_back(X);
    }
    vector<int> check(N, NIL);
    int tmp = 1;
    rep(i, N) {
        if (check[i] == NIL && !G[i].empty()) {
            check[i] = tmp;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int now = q.front(); q.pop();
                rep(j, G[now].size()) {
                    if (check[G[now][j]] == NIL) {
                        check[G[now][j]] = tmp;
                        q.push(G[now][j]);
                    }
                }
            }
            tmp++;
        }
    }
    int ans = vmax(check);
    //rep(i, N) cout << check[i] << " ";
    //cout << endl;
    //cout << ans << endl;
    rep(i, N) {
        if (check[i] == NIL) ans++;
    }
    cout << ans << endl;

}
