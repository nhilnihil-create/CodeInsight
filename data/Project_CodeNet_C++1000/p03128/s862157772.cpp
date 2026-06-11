#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=(ll)(k);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int mod=1e9+7;
const ll inf=1001001001001001;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}

int main(){
    vi cost={0,2,5,5,4,5,6,3,7,6};
    ll n,m;cin>>n>>m;
    vector<bool> ok(10,false);
    rep(i,m){
        int a;cin>>a;ok[a]=true;
    }
    vi dp(n+1,-inf);
    dp[0]=0;
    REP(i,1,n+1){
        rep(j,10)if(ok[j])if(i>=cost[j])chmax(dp[i],dp[i-cost[j]]+1);
    }
    int s=dp[n],w=n;
    vi ans(s);
    rep(i,s){
        for(int j=9;j>0;j--){
            if(!ok[j])continue;
            if(w-cost[j]<0)continue;
            if(dp[w-cost[j]]==s-i-1){
                w-=cost[j];
                ans[i]=j;
                break;
            }
        }
    }
    rep(i,s)cout<<ans[i];
    cout<<'\n';
}