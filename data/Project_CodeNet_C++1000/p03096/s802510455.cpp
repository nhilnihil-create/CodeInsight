#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod=1e9+7;
int main(){
    ll n,C[200001],dp[200001];
    cin>>n;
    rep(i,n) cin>>C[i];
    vec D;
    D.push_back(C[0]);
    rep(i,n-1) if(C[i]!=C[i+1]) D.push_back(C[i+1]);
    ll num[200001]={0};
    dp[0]=1;
    rep(i,D.size()){
        dp[i+1]=(dp[i]+num[D[i]])%mod;
        (num[D[i]]+=dp[i])%=mod;
    }
    cout<<dp[D.size()]%mod<<"\n";
}