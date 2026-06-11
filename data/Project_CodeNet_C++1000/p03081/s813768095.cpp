#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<pair<char, char>> jumon;
    Rep (i, Q) {
        char t, d;
        cin >> t >> d;
        jumon.push_back({t, d});
    }

    s = 'x' + s + 'x';
    // cout << s << "\n";

    ll ans = N;

    ll ok = 0, ng = N+1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll now = mid;
        Rep (i, Q) {
            if (s[mid] == jumon[i].first) {
                if (jumon[i].second == 'L') {
                    mid--;
                } else {
                    mid++;
                }
            }
        }
        if (mid == 0) {
            ok = now;
        } else {
            ng = now;
        }
    }

    // cout << ok << " " << ng << "\n";
    
    ans -= ok;

    ok = N+1, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll now = mid;
        Rep (i, Q) {
            if (s[mid] == jumon[i].first) {
                if (jumon[i].second == 'L') {
                    mid--;
                } else {
                    mid++;
                }
            }
        }
        if (mid == N+1) {
            ok = now;
        } else {
            ng = now;
        }
    }

    // cout << ok << " " << ng << "\n";

    ans -= N+1-ok;

    cout << ans << endl;
}