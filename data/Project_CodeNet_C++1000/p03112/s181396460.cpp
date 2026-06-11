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
    vector<ll> s, t;
    s.emplace_back(-INF);
    t.emplace_back(-INF / 2);
    s.emplace_back(-INF / 3);
    for(int i=0; i<a; i++){
        ll S; cin>>S;
        s.emplace_back(S);
    }
    for(int i=0; i<b; i++){
        ll T; cin>>T;
        t.emplace_back(T);
    }
    s.emplace_back(INF / 3);
    t.emplace_back(INF / 2);
    s.emplace_back(INF);

    while(q--){
        ll x; cin>>x;

        // 左神社、近い寺
        ll sum1 = 0;
        auto shrine = lower_bound(all(s), x);
        shrine--;
        sum1 += abs(x - *shrine);
        auto templer = lower_bound(all(t), *shrine);
        auto templel = templer--;
        sum1 += min(abs(*shrine - *templer), abs(*shrine - *templel));

        // 右神社、近い寺
        ll sum2 = 0;
        shrine = lower_bound(all(s), x);
        sum2 += abs(x - *shrine);
        templer = lower_bound(all(t), *shrine);
        templel = templer--;
        sum2 += min(abs(*shrine - *templer), abs(*shrine - *templel));

        // 左寺、近い神社
        ll sum3 = 0;
        auto temple = lower_bound(all(t), x);
        temple--;
        sum3 += abs(x - *temple);
        auto shriner = lower_bound(all(s), *temple);
        auto shrinel = shriner--;
        sum3 += min(abs(*temple - *shriner), abs(*temple - *shrinel));

        // 右寺、近い神社
        ll sum4 = 0;
        temple = lower_bound(all(t), x);
        sum4 += abs(x - *temple);
        shriner = lower_bound(all(s), *temple);
        shrinel = shriner--;
        sum4 += min(abs(*temple - *shriner), abs(*temple - *shrinel));

        ll ans = min({sum1, sum2, sum3, sum4});

        cout << ans << endl;
    }

    return 0;
}