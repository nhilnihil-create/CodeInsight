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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> dt(n);
    map<int, int> mp;
    rep(i, n) {
        int t;
        ll d;
        cin >> t >> d;
        dt[i] = make_pair(d, t);
    }
    sort(dt.rbegin(), dt.rend());
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    //priority_queue<pair<ll, int>> que;
    ll sum = 0;
    rep(i, k) {
        if (mp[dt[i].second] > 0) {
            que.push(dt[i]);
        }
        ++mp[dt[i].second];
        sum += dt[i].first;
    }
    ll ans = sum + (ll)(mp.size()) * (ll)(mp.size());
    for (int i = k; i < n; ++i) {
        if (mp[dt[i].second] > 0) continue;
        if(que.empty()) break;
        ll d = que.top().first;
        int t = que.top().second;
        que.pop();
        sum += dt[i].first - d;
        --mp[t];
        ++mp[dt[i].second];
        ans = max(ans, sum + (ll)(mp.size()) * (ll)(mp.size()));
    }
    cout << ans << endl;
    return 0;
}
