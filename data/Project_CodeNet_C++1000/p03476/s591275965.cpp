// https://atcoder.jp/contests/abc084/tasks/abc084_d

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF (1e9)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define LEN(x) (sizeof(x) / sizeof(*(x)))
ll gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
ll lcm(long a, long b) { return a * b / gcd(a, b); }

int dp[100001];
bool isPrime(int num) {
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    REP(i, n) cin >> l[i] >> r[i];
    for (int i = 1; i <= 100000; i++) {
        dp[i] = dp[i - 1] + (isPrime(i) & isPrime((i + 1) / 2));
    }

    for (int i = 0; i < n; i++) {
        cout << dp[r[i]] - dp[l[i] - 1] << endl;
    }

    return 0;
}
