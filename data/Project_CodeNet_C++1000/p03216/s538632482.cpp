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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    string s;
    cin >> n >> s >> q;
    vll k(q); REP(i, q) cin >> k[i];
    REP(i, q) {
        ll dc=0, mc=0, dmc=0, ans=0;
        REP(j, s.size()) {
            if (s[j] == 'D') dc++;
            else if (s[j] == 'M') {mc++; dmc+=dc;}
            else if (s[j] == 'C') {
                ans += dmc;
            }
            if (j >=k[i]-1) {
                if (s[j-k[i]+1] == 'D') {dc--; dmc-=mc;}
                else if (s[j-k[i]+1] == 'M') mc--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
