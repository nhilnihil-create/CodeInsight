#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forlr(i, l, r) for (int i = int(l); i <= int(r); i++)
#define repeat(n) for (int hjfjke = 0; hjfjke < int(n); hjfjke++)
#define all(c) c.begin(), c.end()
#define ll long long

int mod = 1000000007;

inline int add(int a, int b);
inline int mult(int a, int b);
inline int sub(int a, int b);

int l[200500];
int r[200500];
int a[200500];

long long mx[800500];
long long ad[800500];

void add(int v, int l, int r, int a, int b, long long c) {
    if (r <= a || b <= l)
        return;

    if (a <= l && r <= b) {
        ad[v] += c;
        mx[v] += c;
        return;
    }

    int m = (l + r) >> 1;

    add(v + v + 1, l, m, a, b, c);
    add(v + v + 2, m, r, a, b, c);

    mx[v] = max(mx[v + v + 1], mx[v + v + 2]) + ad[v];
}

long long get(int v, int l, int r, int a, int b) {
    if (r <= a || b <= l)
        return -1e18;

    if (a <= l && r <= b) {
        return mx[v];
    }

    int m = (l + r) >> 1;
    return max(get(v + v + 1, l, m, a, b), get(v + v + 2, m, r, a ,b));
}

struct block {
    int w, s, v;

    bool operator<(block &other) {
        return s + w < other.s + other.w;
    }
};


block b[1005];

int32_t main() {
    std::iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        block a;
        cin >> a.w >> a.s >> a.v;
        b[i] = a;
    }

    sort(b, b + n);

    vector<long long> dp(20005);

    forn(j, 20005)
    dp[j] = -1e18;

    dp[0] = 0;

    forn(i, n) {
        vector<long long> new_dp(20005, -1e18);

        forn (j, 20005) {
            new_dp[j] = max(new_dp[j], dp[j]);

            if (j <= b[i].s && dp[j] > -1e17)
                new_dp[j + b[i].w] = max(new_dp[j + b[i].w], dp[j] + b[i].v);
        }

        dp = std::move(new_dp);

        /*forn(j, 7)
            cout << dp[j] << " ";
        cout << "\n";*/
    }

    long long ans = 0;

    forn(j, 20005)
        ans = max(ans, dp[j]);

    cout << ans;

    return 0;
}

int add(int a, int b) {
    int result = a + b;
    if (result >= mod)
        result -= mod;
    return result;
}

int sub(int a, int b) {
    int result = a - b;
    if (result < 0)
        result += mod;
    return result;
}

int mult(int a, int b) {
    return (a * 1ll * b) % mod;
}