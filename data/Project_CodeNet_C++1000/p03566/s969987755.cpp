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

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<pll> t(n);
    vector<double> v(n);
    ll sum=0;
    rep(i,n){
        ll d;
        cin >> d;
        if(i==0){
            t[i].fi=0;
            t[i].se=2*d;
        }
        else{
            t[i].fi=t[i-1].se;
            t[i].se=t[i].fi+2*d;
        }
    }
    vector<double> maxv(t[n-1].se+1);
    
    rep(i,n){
        cin >> v[i];
    }
    rep(i,n){
        for(ll j=t[i].fi;j<=t[i].se;j++){
            if(j==t[i].fi){
                maxv[j]=min(maxv[j],v[i]);
            }
            else{
                maxv[j]=v[i];
            }
        }
    }
    maxv[t[n-1].se]=0;
    for(ll i=1;i<=t[n-1].se;i++){
        maxv[i]=min(maxv[i],maxv[i-1]+0.5);
    }
    for(ll i=t[n-1].se-1;i>=0;i--){
        maxv[i]=min(maxv[i],maxv[i+1]+0.5);
    }
    double ans=0;
    for(ll i=1;i<=t[n-1].se;i++){
        ans+=(maxv[i-1]+maxv[i])*0.5*0.5;
    }
    cout << fixed << setprecision(30);
    cout << ans << endl;
}