#include <bits/stdc++.h>
//#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////



int main(){fastio
    
    ll n,c;cin>>n>>c;
    ll d[c][c];rep(i,0,c-1)rep(j,0,c-1)cin>>d[i][j];
    
    /*
    ll dp[c][c];
    rep(goal,0,c-1){
        rep(i,0,c-1)dp[i][goal]=inf;
        dp[goal][goal]=0;
        priority_queue<l_l,vector<l_l>,greater<l_l>>q;q.push({0,goal});
        while(!q.empty()){
            l_l t=q.top();q.pop();
            rep(i,0,c-1){
                if(i==t.se)continue;
                if(dp[i][goal]>dp[t.se][goal]+d[i][t.se]){
                    dp[i][goal]=dp[t.se][goal]+d[i][t.se];
                    q.push({dp[i][goal],i});
                }
            }
        }
    }*/
    /*
    rep(i,0,c-1){
        rep(j,0,c-1)cout<<dp[i][j]<<" ";cout<<endl;
    }cout<<endl;*/
    
    ll a[n][n];rep(i,0,n-1)rep(j,0,n-1){cin>>a[i][j];a[i][j]--;}
    
    ll ep[3][c];memset(ep,0,sizeof(ep));
    rep(i,0,n-1)rep(j,0,n-1){
        ll k=(i+j)%3;
        rep(q,0,c-1){
            ep[k][q]+=d[a[i][j]][q];//dp[a[i][j]][q];
        }
    }
    /*
    rep(i,0,2){
        rep(j,0,c-1)cout<<ep[i][j]<<" ";cout<<endl;
    }*/
    
    ll ans=inf;
    rep(c1,0,c-1)rep(c2,0,c-1)rep(c3,0,c-1){
        if(c1==c2||c2==c3||c3==c1)continue;
        Min(ans,ep[0][c1]+ep[1][c2]+ep[2][c3]);
    }
    cout<<ans<<endl;
    
    
    
    return 0;
}
