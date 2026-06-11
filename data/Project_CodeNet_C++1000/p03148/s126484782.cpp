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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vll t(n), d(n);
    REP(i, n) {
        cin >> t[i] >> d[i];
        t[i]--;
    }
    vll ord(n); iota(ord.begin(), ord.end(), 0LL);
    sort(ord.begin(), ord.end(), [&](ll i, ll j) {
        return d[i] > d[j];
    });
    vll count(n, 0);
    ll cnt = 0, ans = 0;
    REP(i, k) {
        ans += d[ord[i]];
        count[t[ord[i]]]++;
        if (count[t[ord[i]]] == 1) cnt++;
    }
    ans += cnt*cnt;
    
    ll tmp = ans;
    priority_queue<P<ll, ll> > que;
    REP(i, k) if (count[t[ord[i]]] >= 2) que.push(make_pair(-d[ord[i]], t[ord[i]]));
    rep(i, k, n) {
        if (que.empty()) break;
        if (count[t[ord[i]]] == 0) {
            P<ll, ll> q = que.top(); que.pop();
            while (!que.empty() && count[q.second] == 1) {
                q = que.top(); que.pop();
            }
            if (count[q.second] == 1) continue;
            count[q.second]--;
            tmp += q.first;
            tmp += d[ord[i]];
            count[t[ord[i]]] = 1;
            tmp -= cnt*cnt;
            cnt++;
            tmp += cnt*cnt;
            chmax(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}
