#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define INF 0x3f3f3f3f3f
//#define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 20;

int n;
pii a[1 << N];

pii merge(pii A, pii B) {
    if(A.fi < B.fi) swap(A, B);
    pii ans = A;
    if(B.fi > ans.se) ans.se = B.fi;
    return ans;
}

void run() {
    for(int i = 0; i < 1 << n; i++) {
        int x; cin >> x;
        a[i] = MP(x, -INF);
    }
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < 1 << n; i++) {
            if(i >> j & 1) a[i] = merge(a[i], a[i ^ (1 << j)]);
        }
    }
    int ans = 0;
    for(int i = 1; i < 1 << n; i++) {
        ans = max(ans, a[i].fi + a[i].se);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../put/a.input", "r", stdin);
    freopen("../put/a.output", "w", stdout);
#endif
    while(cin >> n) run();
    return 0;
}