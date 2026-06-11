#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);

    rep(i, D) cin >> p[i] >> c[i];

    int ans = 1e9;
    rep(bit, 1 << D) {
        int res = 0;
        int cost = 0;
        rep(i, D) {
            if ((bit >> i) & 1) {
                res += ((i + 1) * 100) * p[i] + c[i];
                cost += p[i];
            }
        }
        rep(i, D) {
            if (res >= G) break;
            if ((bit >> (D - i - 1)) & 1) continue;
            rep(j, p[D - i - 1]) {
                res += (D - i) * 100;
                cost++;
                if (res >= G) break;
            }
            if (res >= G) break;
            res += c[D - i - 1];
        }
        chmin(ans, cost);
    }

    cout << ans << endl;
    return 0;
}