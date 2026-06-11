#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_L = 100000;

// エラトステネスの篩
// n以下の素数の数を返す O(n*loglogn)
int sieve(int n, bool is_prime[], int prime[]) {
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = true;

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    return p;
}

// 素数判定機
bool check_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    ll Q;
    cin >> Q;
    ll l[Q], r[Q];

    rep(i, Q) { cin >> l[i] >> r[i]; }

    bool is_prime[MAX_L + 1];
    int prime[MAX_L];  // i番目の素数
    sieve(MAX_L, is_prime, prime);

    ll a[MAX_L];
    rep(i, MAX_L) {
        a[i] = 0;

        if (i % 2 == 0) continue;

        if (is_prime[i] && is_prime[(i + 1) / 2]) a[i] = 1;
    }

    ll s[MAX_L + 1];
    rep(i, MAX_L + 1) { s[i] = 0; }
    rep(i, MAX_L) { s[i + 1] = s[i] + a[i]; }

    rep(i, Q) { cout << s[r[i] + 1] - s[l[i]] << endl; }

    return 0;
}