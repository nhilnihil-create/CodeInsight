#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
#define MOD 1000000007
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
int main(){
    lint n;
    cin>>n;
    vector<lint> dp(n,INF);
    priority_queue<pair<lint,lint>,vector<pair<lint,lint>>,greater<pair<lint,lint>>> que;
    dp[1]=1;
    que.emplace(1,1);
    while(!que.empty()){
        lint d=que.top().second;
        que.pop();
        if(chmin(dp[(d*10)%n],dp[d]))que.emplace(dp[d],(d*10)%n);
        if(chmin(dp[(d+1)%n],dp[d]+1))que.emplace(dp[d]+1,(d+1)%n);
    }
    cout<<dp[0];
}
