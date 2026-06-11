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

ll power(ll n, ll p) {
    ll ret = 1;
    rep(i, p) { ret *= n; }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    ll res = power(3, N);
    ll ng = 1;
    rep(i, N) {
        if(A[i] % 2 == 1) {

        } else {
            ng *= 2;
        }
    }
    cout << res - ng << endl;
    return 0;
}