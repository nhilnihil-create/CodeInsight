#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), c(m), q(2);
    map<ll,ll> num;
    rep1(i, n){
        cin >> a[i];
        if (num.count(a[i])) num[a[i]] += 1;
        else num[a[i]] = 1;
    }
    priority_queue<vector<ll>> pq;
    rep1(i, n){
        if (num.count(a[i])){
            q[0] = a[i];
            q[1] = num[a[i]];
            num.erase(a[i]);
            pq.push(q);
        }
    }
    rep1(i, m){
        cin >> b[i] >> c[i];
        q[0] = c[i];
        q[1] = b[i];
        pq.push(q);
    }
    ll ans=0, res=n, cnt;
    while (res > 0){
        q = pq.top(); pq.pop();
        ans += q[0] * min(q[1], res);
        res -= q[1];
    }
    cout << ans << endl;
}