#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

vll dc(13, 0), ddd(25, 0);

ll dfs(ll x) {
    if (x==12) {
        ll ret=HIGHINF;
        REP(i, 24) {
            rep(j, i+1, 24) {
                if (ddd[i]&&ddd[j]) ret = min({ret, j-i, 24-j+i});
            }
        }
        return ret;
    }
    if (dc[x]==0) return dfs(x+1);
    ddd[x]++;
    ll m1 = dfs(x+1);
    ddd[x]--; ddd[24-x]++;
    ll m2 = dfs(x+1);
    ddd[24-x]--;
    return max(m1, m2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll d(n); REP(i, n) cin >> d[i];
    ddd[0]++;
    REP(i, n) {
        dc[d[i]]++;
        if (d[i]==0 || dc[d[i]]>2 || (d[i]==12 && dc[d[i]]>1)) {
            cout << 0 << '\n'; return 0;
        } else if (dc[d[i]]==2) {
            ddd[d[i]]++; ddd[24-d[i]]++;
        }
    }
    if (dc[12]) ddd[12]++;
    cout << dfs(1) << endl;
    return 0;
}
