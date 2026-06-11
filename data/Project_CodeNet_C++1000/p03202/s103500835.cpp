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
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n); REP(i, n) cin >> a[i];

    ll low = 0, high = n;
    while (low < high) {
        ll mid = (low + high) >> 1;

        set< P<ll, ll> > ad;
        bool is_val = true;
        rep(i, 1, n) {
            if (a[i] <= a[i - 1]) {
                while (ad.size() > 0 && (*ad.rbegin()).first > a[i]) ad.erase(*ad.rbegin());
                for (ll j = a[i]; j >= 0; j--) {
                    if (j == 0) {
                        is_val = false;
                    } else {
                        if (ad.size() > 0 && (*ad.rbegin()).first == j) {
                            if ((*ad.rbegin()).second < mid - 1) {
                                P<ll, ll> end = *ad.rbegin();
                                ad.erase(*ad.rbegin());
                                end.second++;
                                ad.insert(end);
                                break;
                            } else {
                                ad.erase(*ad.rbegin());
                            }
                        } else {
                            if (mid == 1) {
                                is_val = false;
                            } else {
                                ad.insert(make_pair(j, 1));
                            }
                            break;
                        }
                    }
                }
            }
        }

        if (!is_val) low = mid + 1;
        else high = mid;
    }

    if (high == 0) high++;
    cout << high << '\n';
    return 0;
}
