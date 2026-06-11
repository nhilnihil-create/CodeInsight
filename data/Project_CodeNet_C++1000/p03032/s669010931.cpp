#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n)cin >> v[i];

    ll ans = 0;
    rep(left, min(n+1, k+1))rep(right, min(n+1-left, k+1-left)){
        priority_queue<ll, vector<ll>, greater<ll>> que;
        rep(i, left)que.push(v[i]);
        rep(i, right)que.push(v[n-1-i]);

        rep(i, min(k-left-right, left+right)){
            if(que.top() >= 0)break;
            que.pop();
        }
 
        ll res = 0;
        while(!que.empty()){
            res += que.top();
            que.pop();
        }

        ans = max(ans, res);
    }

    cout << ans << endl;
}