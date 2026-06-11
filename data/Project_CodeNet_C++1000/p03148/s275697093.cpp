#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<40;
/* -- template -- */

int main() {
    ll N, K; cin >> N >> K;
    vector<vector<ll>> sushi(N);
    rep(i, N) {
        ll t, d; cin >> t >> d;
        --t;sushi[t].push_back(d);
    }
    for(auto &v : sushi) {
        sort(v.begin(), v.end(), greater<ll>());
        if(v.empty())v.push_back(-LLINF);
    }
    sort(sushi.begin(), sushi.end(), [&](vector<ll> a, vector<ll> b){
        return a[0] > b[0];});
    ll cur = 0;
    priority_queue<long long> que;
    for(int i = 0;i < K;++i) {
        cur += sushi[i][0];
        for(int j = 1; j < sushi[i].size(); ++j){
            que.push(sushi[i][j]);
        }
    }
    for(int i = K; i < N; ++i) {
        for(int j = 0; j < sushi[i].size(); ++j)
            que.push(sushi[i][j]);
    }
    ll ans = cur + K * K;
    for(ll i = K - 1;i > 0;--i){
        ll t = que.top();
        if(sushi[i][0] < t) {
            que.pop();
            cur -= sushi[i][0];
            cur += t;
            que.push(sushi[i][0]);
        }
        ans = max(ans, cur + i * i);
    }
    cout << ans << endl;
}
