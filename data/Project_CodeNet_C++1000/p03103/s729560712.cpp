#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;

int main() {
    ll n, m;
    cin >> n >> m;
    priority_queue<Pl, vector<Pl>, greater<Pl>> q;
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        q.emplace(a,b);
    }
    ll ans = 0, cnt = 0;
    while (cnt < m) {
        auto p = q.top();
        q.pop();
        ans += p.first*min(m-cnt,p.second);
        cnt += min(m,p.second);
    }
    cout << ans << endl;
    return 0;
}