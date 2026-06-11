#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
//const ll mod=1000000007;
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
pair<int,int> dp[(1<<18)+5]={};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        cin>>dp[i].fi;
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<(1<<n);i++){
            if(i&(1<<j)){
                V<int> d={dp[i].fi,dp[i].se,dp[i&~(1<<j)].fi,dp[i&~(1<<j)].se};
                sort(all(d),greater<int>());
                dp[i].fi=d[0];
                dp[i].se=d[1];
            }
        }
    }
    int ans=-1;
    for(int i=1;i<(1<<n);i++){
        chmax(ans,dp[i].fi+dp[i].se);
        cout<<ans<<"\n";
    }
}