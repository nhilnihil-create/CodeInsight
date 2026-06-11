#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

//拡張ユークリッドの互除法
int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

// mod逆元
int mod_inverse(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

// 階乗、階乗逆元テーブル
int fact[1100000], fact_inv[1100000], inv[1100000];

int mod_fact(int n, int m) {
    fact[0] = fact_inv[0] = 1;
    inv[1] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % m;
        inv[i] = m - inv[m % i] * (m / i) % m;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % m;
    }
}

int N;
int A[110000], xt[110000];
int mod = 1e9 + 7;

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++)cin >> A[i];
    mod_fact(110000, mod);
    for (int i = 2; i < 110000; i++) {
        xt[i] = (xt[i - 1] + fact[N] * mod_inverse(i, mod) % mod) % mod;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        (ans += (xt[i + 1] + xt[N - i] + fact[N]) * A[i] % mod) %= mod;
    }
    cout<<ans<<endl;

}