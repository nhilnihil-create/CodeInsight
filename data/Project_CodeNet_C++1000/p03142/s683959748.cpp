#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;


int main(){
    ll n,m;
    cin >> n >> m;
    vector<set<ll>> from(n);
    vector<set<ll>> to(n);
    rep(i,n+m-1){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        from[b].insert(a);
        to[a].insert(b);
    }
    priority_queue<pll> PQ;
    vector<ll> ans(n);
    rep(i,n){
        PQ.push({n-from[i].size(),i});
    }
    ll p=0;
    pll st=PQ.top();
    ans[st.se]=0;
    ll cnt=1;
    while(cnt<n){
        pll x=PQ.top();
        PQ.pop();
        p=x.fi;
        for(auto c:to[x.se]){
            if(from[c].size()==1){
                ans[c]=x.se+1;
                cnt++;
                PQ.push({n,c});
            }
            from[c].erase(x.se);
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}
