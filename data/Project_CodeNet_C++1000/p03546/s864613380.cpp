//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll h,w; cin>>h>>w;
    vector<vector<ll>>c(10,vector<ll>(10));
    rep(i,10){
        rep(j,10)cin>>c[i][j];
    }
    vector<vector<ll>>a(h,vector<ll>(w));
    rep(i,h){
        rep(j,w)cin>>a[i][j];
    }
    rep(k,10){
        rep(i,10){
            rep(j,10){
                if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];
            }
        }
    }
    ll ans=0;
    rep(i,h){
        rep(j,w){
            if(a[i][j]>=0){
                ans+=c[a[i][j]][1];
            }
        }
    }
    cout<<ans<<endl;
}









