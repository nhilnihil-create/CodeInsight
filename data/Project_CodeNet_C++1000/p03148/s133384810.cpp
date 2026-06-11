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

const ll INF=1e18;

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> t(n),p;
    vector<pll> d(n);
    map<ll,ll> m;
    rep(i,n){
        cin >> t[i];
        cin >> d[i].fi;
        m[t[i]]=max(m[t[i]],d[i].fi);
    }
    rep(i,n){
        if(m[t[i]]==d[i].fi){
            d[i].se=1;
            p.push_back(d[i].fi);
            m[t[i]]=INF;
        }
    }
    sort(p.rbegin(),p.rend());
    sort(d.rbegin(),d.rend());
    ll sum=0;
    ll s=0;
    multiset<ll> mu;
    rep(i,k){
        sum+=d[i].fi;
        s+=d[i].se;
        if(d[i].se==0){
            mu.insert(d[i].fi);
        }
    }
    sum+=s*s;
    
    ll ans=sum;
    ll sz=p.size();
    for(ll i=s;i<sz;i++){
        if(mu.size()==0) break;
        sum+=p[i];
        ll v=*mu.begin();
        mu.erase(mu.find(v));
        sum-=v;
        sum+=2*i+1;
        ans=max(ans,sum);
    }
    cout << ans << endl;
    return 0;
} 