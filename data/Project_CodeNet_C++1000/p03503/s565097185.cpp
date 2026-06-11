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
    ll n; cin>>n;
    vector<vector<ll>>f(n,vector<ll>(10));
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    vector<vector<ll>>p(n,vector<ll>(11));
    rep(i,n){
        rep(j,11)cin>>p[i][j];
    }
    ll ans=-INF;
    ll mx=0;
    for(int tmp=1;tmp<(1<<10);tmp++){
        bitset<10>b(tmp);
        mx=0;
        rep(i,n){
            string s="";
            rep(j,10){
                s+=to_string(f[i][j]);
            }
            bitset<10>S(s);
            ll num=(S&b).count();
            mx+=p[i][num];
        }
        ans=max(ans,mx);
    }
    cout<<ans<<endl;
}









