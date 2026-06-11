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

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll v=0;
    ll le=0,ri=0;
    ll ans=0;
    rep(i,n){
        le=i;
        ri=max(ri,i);
        if(le==ri) v=a[le];
        while(true){
            bool ok=true;
            if(ri==n-1) break;
            rep(j,20){
                if((v>>j)%2==1 && ((a[ri+1])>>j)%2==1){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ri++;
                v^=a[ri];
            }
            else break;
            if(ri==n-1) break;
        }
        //cout << v << endl;
        ans+=(ri-le)+1;
        v^=a[le];
        
    }
    cout << ans << endl;
} 
