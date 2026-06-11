#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

map< int64_t, int > prime_factor(int64_t n) {
    map< int64_t, int > ret;
    for (int64_t i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    int n,sum=0;
    ll a;
    cin >> n;
    rep(i, n) {
        cin >> a;
        auto s = prime_factor(a);
        sum += s[2];
    }
    cout << sum << endl;
    return 0;
}