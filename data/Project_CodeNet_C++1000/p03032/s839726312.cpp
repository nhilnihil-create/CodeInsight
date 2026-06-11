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

int main() {
    int N, K; cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];
    int ans = 0;
    for (int l = 0; l <= min(N, K); l++) {
        for (int r = 0; l+r <= min(N,K); r++) {
            if (l+r > min(N, K)) break;
            vector<int> tmp;
            rep(i, l) tmp.push_back(V[i]);
            rep(i, r) tmp.push_back(V[N-1-i]);
            sort(ALL(tmp));
            reverse(ALL(tmp));
            int cnt = 0;
            rep(i, tmp.size()) {
                if (K-l-r >= tmp.size()-i && tmp[i] < 0) break;
                else cnt += tmp[i];
            }
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;

}
