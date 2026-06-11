#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(ll i=ll(x);i<(ll)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<ll, ll>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;

bool f(ll a, ll b) {
    return a > b;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>>x(n);
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        t--;
        x[t].push_back(d);
    }
    rep(i, n) {
        sort(x[i].begin(), x[i].end(), f);
        if(x[i].empty())x[i].push_back(-INF);
    }
    priority_queue<ll>pq, cq;
    rep(i, n) {
        pq.push(x[i][0]);
        arep(j, 1, (ll)x[i].size()) {
            cq.push(x[i][j]);
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>>q;
    ll sum=0;
    rep(i,k){
        sum+=pq.top();
        q.push(pq.top());
        pq.pop();
    }
    ll ans = sum +k*k;
    
    for(ll x=k-1;x>0;x--){
        sum -= q.top(); 
        cq.push(q.top());
        q.pop();
        sum += cq.top(); cq.pop();

        ans = max(ans, sum + x * x);
    }
    cout << ans << endl;


    return 0;
}