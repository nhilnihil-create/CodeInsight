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
    ll n, k;
    string s;
    cin >> n >> k >> s;

    vl v0, v1;
    if(s[0] == '0') {
        v1.pb(0);
    }
    ll cnt0 = 0, cnt1 = 0;
    rep(i, n) {
        if(i > 0 && s[i-1] == '0' && s[i] == '1') {
            v0.pb(cnt0);
            cnt0 = 0;
        }
        else if(i > 0 && s[i-1] == '1' && s[i] == '0') {
            v1.pb(cnt1);
            cnt1 = 0;
        }
        if(s[i] == '0') {
            cnt0++;
        }
        else {
            cnt1++;
        }
    }
    if(s[n-1] == '0') {
        v0.pb(cnt0);
        v1.pb(0);
    }
    else {
        v1.pb(cnt1);
    }

    if(k >= v0.size()) {
        out(n);
        re0;
    }

    ll m = v0.size();
    vl rui0(m+1);  // rui0[i+1] : v0[i]までの和
    vl rui1(m+2);  // rui1[i+1] : v1[i]までの和
    rep(i, m) { 
        rui0[i+1] = rui0[i] + v0[i];
    }
    rep(i, m+1) {
        rui1[i+1] = rui1[i] + v1[i];
    }

    ll ans = 1;
    rep(i, m-k+1) {
        chmax(ans, (rui1[i+k+1] - rui1[i]) + (rui0[i+k] - rui0[i]));
    }

    out(ans);
    re0;
}