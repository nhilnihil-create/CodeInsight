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
    string s;
    cin >> s;
    ll n = s.size();

    string t;
    rep(i, n) {
        if(i < n-1 && s[i] == 'B' && s[i+1] == 'C') {
            t.pb('D');
            i++;
        }
        else {
            t.pb(s[i]);
        }
    }

    ll m = t.size();
    ll ans = 0;
    ll cntA = 0;
    rep(i, m) {
        if(t[i] == 'A') {
            cntA++;
        } 
        else if(t[i] == 'D') {
            ans += cntA;
        }
        else {
            cntA = 0;
        }
    }

    out(ans);
    re0;
}