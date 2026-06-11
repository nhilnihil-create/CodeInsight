#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 1e5 + 10 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int D, G , p[maxn] , c[maxn] , ans = INF;

int32_t main() {
    FAST
    cin >> D >> G;
    for (int i = 0; i < D; ++i) {
        cin >> p[i] >> c[i];
    }
    for (int mask = 0; mask < (1ll << D); ++mask) {
        int badmaxi = -1 , sum = 0 , prob = 0;
        for (int i = 0; i < D; ++i) {
            if(mask & (1ll << i)) {
                sum += ((i + 1) * 100 * p[i]) + c[i];
                prob += p[i];
            }
            else {
                badmaxi = i;
            }
        }
        if(badmaxi != -1 && sum < G) {
            int point = 100 * badmaxi + 100;
            int need = (G - sum + (point - 1)) / point;
            if(need >= p[badmaxi]) {
                continue;
            }
            prob += need;
        }
        ans = min(ans , prob);
    }
    cout << ans << '\n';
 }
