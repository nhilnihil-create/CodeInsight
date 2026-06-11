#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, H;
    cin >> N >> H;
    vector<pii> vp(N);
    int a, b;
    for (int i = 0; i < N; i++) { cin >> b >> a; vp[i] = pii(a, b); }
    sort(vp.begin(), vp.end(), greater<pii>());

    int ma = 0;
    for (pii p : vp) { ma = max(ma, p.second); }

    int ans = 0;
    for (int i = 0; i < N && H > 0; i++) {
        if (vp[i].first > ma) {
            H -= vp[i].first;
            ans++;
        }
    }

    if (H > 0) ans += (H + ma - 1) / ma;
    cout << ans << '\n';
}
