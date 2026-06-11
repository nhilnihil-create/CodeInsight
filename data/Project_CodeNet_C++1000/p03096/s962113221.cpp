//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;
                                                                                                     
ll MOD=1000000007;                                                                                     
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n; cin>>n;
    vector<ll> c(n,0),cl;
    rep(i,n){
        cin>>c[i]; c[i]--;
    }
    rep(i,n-1){
        if(c[i]!=c[i+1]) cl.push_back(c[i]);
    }
    cl.push_back(c.back());
    ll N=cl.size();
    vector<ll> dp(N+1,0),h(200000,0);
    dp[1]=1; h[cl[0]]=1;
    for(int i=2;i<=N;i++){
        dp[i]=(dp[i-1]+dp[h[cl[i-1]]])%MOD;
        h[cl[i-1]]=i;
    }
    cout<<dp[N]<<endl;
}