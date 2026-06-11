// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t-->0) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b>a) cout << "No\n";
        else if (d<b) cout << "No\n";
        else if (c>=b) cout << "Yes\n";
        else {
            ll bd = gcd(b, d);
            if (b-bd+(a%bd) > c) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}
