#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> d(n);
    rep(i, n) {
        int cost, drink;
        cin >> cost >> drink;
        d[i] = make_pair(cost, drink);
    }
    sort(d.begin(), d.end());
    //for (auto p: d) {
    //    cout << p.first << " " << p.second << endl;
    //}
    ll ans = 0;
    ll now_num = 0;
    //cout << "test" << endl;
    rep(i, n) {
        if (now_num + d[i].second >= m) {
            ans += d[i].first * (m - now_num);
            break;
        }
        else {
            ans += d[i].first * d[i].second;
            now_num += d[i].second;
        }
        //cout << ans << " " << now_num << endl;
    }
    cout << ans << endl;
    return 0;
}
