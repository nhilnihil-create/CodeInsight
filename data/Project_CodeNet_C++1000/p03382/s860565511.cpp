#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 1e9 + 9;
const ll linf  = 1ll * inf * inf;
const int N = 500000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

int n, a[N];

void solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int mx = a[n - 1];

    int best = -inf;

    rep(i, 0, n - 1) {
        if (mx & 1) {
            if (abs(a[i] * 2ll - mx) < abs(best * 2ll - mx)) {
                best = a[i];
            }
        } else {
            if (abs(a[i] - mx / 2) < abs(best - mx / 2)) {
                best = a[i];
            }
        }
    }

    cout << mx << ' ' << best << '\n';
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
#endif
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
        //		printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}
