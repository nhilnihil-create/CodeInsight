#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

int N;
int c;
vvi a;
vector<int> memo;

int rec(int bits) {
    if (memo[bits] != -inf) {
        return memo[bits];
    }
    int ret = 0;
    rep(i, N) for (int j = i + 1; j < N; j++) if ((bits >> i & 1) && (bits >> j & 1)) {
        ret += a[i][j];
    }
    for (int b = (bits - 1) & bits; b > 0; b = (b - 1) & bits) {
        chmax(ret, rec(b) + rec(b ^ bits));
    }

    return memo[bits] = ret;
}

void solve() {
    cout << rec((1 << N) - 1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    scanf("%lld", &N);
    a = std::vector<std::vector<long long>>(N, std::vector<long long>(N));
    memo = vi(1 << N, -inf);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    solve();
    return 0;
}
