#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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

int main() {
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll lcm = N * M / __gcd(N, M);
    if(N > M) {
        swap(N, M);
        swap(S, T);
    }
    ll c = lcm / N, d = lcm / M;

    bool ok = 1;
    rep(i, N) {
        if((i * c) % d == 0) {
            if(S[i] != T[(i * c) / d])
                ok = 0;
        }
    }
    cout << (ok ? lcm : -1) << endl;
    return 0;
}