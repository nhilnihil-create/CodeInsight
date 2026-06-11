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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> sum(N + 1);
    vector<ll> cood;
    rep(i, N) sum[i + 1] = sum[i] + A[i];
    rep(i, N) {
        for(int j = i + 1; j < N + 1; j++) {
            cood.pb(sum[j] - sum[i]);
        }
    }

    ll res = 0;
    for(int i = 50; i >= 0; i--) {
        vector<ll> next_cood;
        rep(j, cood.size()) {
            if(cood[j] & (1LL << i))
                next_cood.pb(cood[j]);
        }
        if(next_cood.size() < K) {

        } else {
            res += (1LL << i);
            cood = next_cood;
        }
    }
    cout << res << endl;

    return 0;
}