#include <bits/stdc++.h>
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
using namespace std;
ll l[MAXN], r[MAXN];

int main() {
    int n;
    ni(n);
    for (int i = 0; i < n; i++)
        nl(l[i]), nl(r[i]);
    l[n] = r[n] = 0;
    sort(l, l+n+1);
    reverse(l,l+n+1);
    sort(r,r+n+1);
    ll ans = 0, sm = 0;
    for (int i = 0; i <= n; i++) {
    	sm += 2 * (l[i] - r[i]);
    	ans = max(ans, sm);
    }
    prl(ans);
    return 0;
}
