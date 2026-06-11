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
    ll n;
    cin >> n;
    vector<ll> p(n+1);
    vector<pll> prime;
    for(ll i=2;i<=n;i++){
        if(p[i]==0){
            prime.push_back(make_pair(i,0));
            for(ll j=i;j<=n;j+=i){
                p[j]=1;
            }
        }
    }
    ll sz=prime.size();
    rep(i,sz){
        ll val=prime[i].fi;
        while(n/val){
            prime[i].se+=n/val;
            val*=prime[i].fi;
        }
    }
    ll ans=0;
    for(auto x:prime){ //75
        if(x.se>=74) ans++;
    }
    for(auto x:prime){ //25×3
        for(auto y:prime){
            if(x.se>=24 && y.se>=2 && x.fi!=y.fi){
                ans++;
            }
        }
    }
    for(auto x:prime){ //15×5
        for(auto y:prime){
            if(x.se>=14 && y.se>=4 && x.fi!=y.fi){
                ans++;
            }
        }
    }
    for(auto x:prime){
        ll cnt=0;
        for(auto y:prime){
            for(auto z:prime){
                if(x.se>=2 && y.se>=4 && z.se>=4 && x.fi!=y.fi && y.fi!=z.fi && z.fi!=x.fi){
                    cnt++;
                }
            }
        }
        ans+=cnt/2;
    }
    cout << ans << endl;
    return 0;
} 