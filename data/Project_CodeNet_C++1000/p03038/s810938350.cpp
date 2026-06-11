#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<ll,ll>> q;
    rep(i,n) {
        ll a;
        cin >> a;
        q.emplace(a,1);
    }
    rep(i,m) {
        ll b, c;
        cin >> b >> c;
        q.emplace(c,b);
    }
    ll ans = 0;
    rep(i,n) {
        auto p = q.top();
        q.pop();
        ans += p.first;
        if (p.second > 1) {
            q.emplace(p.first, p.second-1);
        }
    }
    cout << ans << endl;
    return 0;
}