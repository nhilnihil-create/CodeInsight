#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n;
ll a[16][16];
ll dp[(1<<16)+1];

ll DP(int bit){
    if(dp[bit]>=0) return dp[bit];
    int m=__builtin_popcount(bit);
    if(m==1) return dp[bit]=0;
    vector<int> id(m);
    int idx=0;
    rep(i,n){
        if((bit>>i)&1){
            id[idx]=i;
            idx++;
        } 
    }
    //ここからグルーピングしない場合
    ll ret=0;
    rep(i,m){
        for(int j=i+1;j<m;j++){
            ret+=a[id[i]][id[j]];
        }
    }

    for(int b=1;b<=(1<<(m-1));b++){
        int bitl=0;
        rep(i,m){
            if((b>>i)&1)bitl+=(1<<id[i]);
        }
        int bitr=bit-bitl;
        ll l,r;
        if(dp[bitl]>=0) l=dp[bitl];
        else l=DP(bitl);
        if(dp[bitr]>=0) r=dp[bitr];
        else r=DP(bitr);
        chmax(ret,l+r);
    }
    // cout<<bitset<3>(bit)<<" : "<<ret<<endl;
    return dp[bit]=ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    rep(i,n){
        rep(j,n){
            cin>>a[i][j];
        }
    }
    rep(i,(1<<16)) dp[i]=-1;
    dp[0]=0;
    cout<<(DP((1<<n)-1))<<endl;
    return 0;
}
