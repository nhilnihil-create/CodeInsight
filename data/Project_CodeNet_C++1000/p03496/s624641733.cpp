#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
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
const ll MAX_N = 100010;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    ll ma = -1;  // aの中で絶対値が最大の数の絶対値
    ll id = -1;  // aの中で絶対値が最大の数のindex
    rep(i, n) {
        cin >> a[i];
        if(ma < abs(a[i])) {
            ma = abs(a[i]);
            id = i+1;
        }
    }

    out(2*(n-1));
    // aの中で絶対値が最大の数を他の数に足しまくる
    exrep(i, 1, n) {
        if(i == id) {
            continue;
        }
        cout << id << " " << i << "\n";
    }

    if(a[id-1] > 0) {  // a[id]を足した後のaの要素が全て正のとき
        // 左から累積和
        exrep(i, 1, n-1) {
            cout << i << " " << i+1 << "\n";
        }
    }
    else {  // a[id]を足した後のaの要素が全て0以下のとき
        // 右から累積和
        for(ll i = n-1; i >= 1; i--) {
            cout << i+1 << " " << i << "\n";
        }
    }

    re0;
}