#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;


signed main(){
    int n,k; cin >> n >> k;
    vector<Pll> v;
    rep(i,n){
        ll x,y; cin >> x >> y;
        v.pb({x,y});
    }
    sort(ALL(v));
    ll ans=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll x1=v[i].fi,x2=v[j].fi;
            vector<ll> vec;
            rep(l,n){
                if(v[i].fi<=v[l].fi && v[l].fi<=v[j].fi) vec.pb(v[l].se);
            }
            if(vec.size()<k) continue;
            sort(ALL(vec));
            ll dy=vec[k-1]-vec[0];
            for(int l=0;k-1+l<vec.size();l++){
                chmin(dy,vec[k-1+l]-vec[l]);
            }
            if(ans==-1) ans=(x2-x1)*dy;
            chmin(ans,(x2-x1)*dy);
        }
    }
    cout << ans << endl;
}

