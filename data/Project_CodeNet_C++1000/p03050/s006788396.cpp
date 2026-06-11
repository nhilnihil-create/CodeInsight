#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.insert(i);
            if(i * i != n)
                ret.insert(n / i);
        }
    }
    return ret;
}

int main() {
    ll N;
    cin >> N;
    auto div = divisor(N);
    ll sum = 0;
    for(auto x : div) {
        if(x != 1 && N % (x - 1) != N / (x - 1))
            continue;
        sum += x - 1;
    }
    cout << sum << endl;
    return 0;
}