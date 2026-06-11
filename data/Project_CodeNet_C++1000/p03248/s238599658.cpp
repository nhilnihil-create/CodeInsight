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

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    if (s[s.size()-1] == '1' || s[0] == '0') cout << -1 << '\n';
    else {
        queue<ll> que;
        REP(i, s.size()-1) {
            if (s[i] != s[s.size()-2-i]) {
                cout << -1 << '\n';
                return 0;
            }
            if (s[i] == '1') que.push(i);
        }
        que.push(s.size()-1);
        REP(i, s.size()-1) {
            if (i == que.front()) que.pop();
            cout << i+1 << ' ' << que.front()+1 << '\n';
        }
    }
    return 0;
}
