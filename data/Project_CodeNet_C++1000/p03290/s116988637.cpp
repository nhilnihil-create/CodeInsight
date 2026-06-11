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
#define INF 2000

int main() {
    int D, G; cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i, D) cin >> p[i] >> c[i];
    int ans = INF, tmp, cnt;
    rep(i, 1<<D) {
        cnt = 0; tmp = 0;
        rep(j, D) {
            if (i&(1<<j)) {
                cnt += p[j];
                tmp += p[j]*(j+1)*100 + c[j];
            }
        }
        rep(j, D) {
            if (tmp >= G) break;
            if (i&(1<<(D-j-1))) continue;
            if (G-tmp >= (p[D-j-1]-1)*(D-j)*100) {
                cnt += p[D-j-1]-1;
                tmp += (p[D-j-1]-1)*(D-j)*100;
            }
            else {
                int div = ((G-tmp)%((D-j)*100) ? (G-tmp)/((D-j)*100)+1 : (G-tmp)/((D-j)*100));
                cnt += div;
                tmp += div * (D-j)*100;
            }
        }
        if (tmp >= G) chmin(ans, cnt);
    }
    cout << ans << endl;
}

