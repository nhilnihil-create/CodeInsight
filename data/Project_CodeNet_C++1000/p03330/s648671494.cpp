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


int main()
{
    ll n,c;
    cin >> n >> c;
    vector<vector<ll>> a(c,vector<ll>(c));
    vector<vector<ll>> b(n,vector<ll>(n));
    rep(i,c){
        rep(j,c){
            cin >> a[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cin >> b[i][j];
        }
    }
    vector<vector<ll>> cost(3,vector<ll>(c,0));
    rep(i,c){
        rep(p,n){
            rep(q,n){
                ll r=(p+q+2)%3;
                ll s=b[p][q]-1;
                if(r==0) cost[0][i]+=a[s][i];
                if(r==1) cost[1][i]+=a[s][i];
                if(r==2) cost[2][i]+=a[s][i];
            }
        }
    }
    ll ans=INF;
    rep(i,c){
        rep(j,c){
            rep(k,c){
                ll sum=0;
                if(i==j || j==k || k==i) continue;
                sum=cost[0][i]+cost[1][j]+cost[2][k];
                ans=min(ans,sum);
            }
        }
    }
    cout << ans <<endl;
    return 0;
} 
