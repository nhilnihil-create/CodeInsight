#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll INF = LLONG_MAX/3;
ll safe_sum(ll a, ll b) {
    if (a == INF) return a;
    if (b == INF) return b;
    return min(a+b, INF);
}

ll safe_prod(ll a, ll b) {
    if (a == INF) return a;
    if (b == INF) return b;
    if (INF/b <= a) return INF;
    return min(INF, a * b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    ll X;
    cin >> N >> X;

    vi x(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];

    vll p(N + 1);
    for (int i = 0; i < N; i++)
        p[i+1] = p[i] + x[i];

    ll fin = LLONG_MAX;
    for (int t = 1; t <= N; t++) {
        WATCH(t);
        ll ans = X * N + X * t;
        for (int j = N - 1, sz = 1; j >= 0; j-=t, sz++) {
            int i = max(0, j - t + 1);
            ll s = p[j+1] - p[i];
            WATCH(j);
            WATCH(i);
            WATCH(s);
            if (sz == 1) ans = safe_sum(ans, 5 * s);
            else ans = safe_sum(ans, (2ll * sz + 1) * s);
        }
        WATCH(ans);
        fin = min(fin, ans);
    }

    cout << fin << endl;
    return 0;
}

