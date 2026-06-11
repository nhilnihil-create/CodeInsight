#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, n) {
        int a;
        cin >> a;
        q.push(a);
    }
    vector<pair<int, int>> b(m);
    rep(i, m) cin >> b[i].first >> b[i].second;
    sort(b.begin(), b.end());
    rep(i, m){
        rep(j, b[b.size() - i - 1].first){
            if (q.top() >= b[b.size() - i - 1].second) {
                break;
            }
            q.pop();
            q.push(b[b.size() - i - 1].second);
        }
    }
    ll ans = 0;
    rep(i, n) {
        //cout << q.top() << ' ';
        ans += q.top();
        q.pop();
    }
    
    cout << ans << endl;
    return 0;
}
