#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, q; cin>>a>>b>>q;
    vector<ll> s(a+2), t(b+2);
    s[0] = t[0] = -INF;
    for(int i=0; i<a; i++) cin>>s[i+1];
    for(int i=0; i<b; i++) cin>>t[i+1];
    s[a+1] = t[b+1] = INF;

    while(q--){
        ll x; cin>>x;

        int sidx = lower_bound(all(s), x) - s.begin();
        int tidx = lower_bound(all(t), x) - t.begin();

        ll ans = INF;
        for(int i=sidx-1; i<=sidx; i++){
            for(int j=tidx-1; j<=tidx; j++){
                chmin(ans, min(abs(x - s[i]) + abs(s[i] - t[j]), abs(x - t[j]) + abs(t[j] - s[i])));
            }
        }

        cout << ans << endl;
    }

    return 0;
}