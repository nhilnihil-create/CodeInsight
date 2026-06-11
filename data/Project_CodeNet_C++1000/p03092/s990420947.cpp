#include<bits/stdc++.h>
#define ll            long long
#define pb            emplace_back
#define fi            first
#define se            second
#define mp            make_pair
//#define int           int64_t

using namespace std;

typedef pair<ll, int> pii;
const int N = (int)5e3 + 5;
const ll inf = (ll)1e18;

int n, A, B, a[N], pos[N];
ll f[N][N], mn;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FileName      "test"
    if(fopen(FileName".inp", "r")) {
       freopen(FileName".inp", "r", stdin);
       freopen(FileName".out", "w", stdout);
    }
    cin >> n >> A >> B;
    fill_n(&f[0][0], N * N, inf);
    for(int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i - 1;
    ///(0, 1], (1, 2], (2, 3], ..., (n - 1, n], (n, n + 1]
    ///to the right A, to the left B
    for(int i = 0; i <= n; ++i) f[1][i] = (i == pos[1]? 0: (i < pos[1]? B: A));
    for(int i = 2; i <= n; ++i) { /// f(i, j) = sort 1 -> i, pos(i) in range (j, j + 1]
        mn = inf;
        for(int j = 0; j <= n; ++j) {
            /// f(i, j) min f(i - 1, k) k < j
            mn = min(mn, f[i - 1][j]);
            f[i][j] = mn + (j == pos[i]? 0: (j < pos[i]? B: A));
        }
    }
    cout << *min_element(f[n], f[n] + n + 1);
}