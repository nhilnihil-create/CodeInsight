#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl dp(2*k);  // dp[i] : 石がi個のとき先手が勝つなら1
    rep(i, k) {
        if(dp[i] == 0) {
            rep(j, n) {
                dp[i + a[j]] = 1;
            }
        }
    }

    if(dp[k]) {
        out("First");
    }
    else {
        out("Second");
    }

    re0;
}