#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin >>n;
    vector<ll>dp(n+1,INF);
    vector<ll>yen;
    yen.push_back(1);
    ll k=1;
    while(k<=n){
        k*=6;
        yen.push_back(k);
    }
    k=1;
    while(k<=n){
        k*=9;
        yen.push_back(k);
    }
    dp[0]=0;
    for (int i = 0; i < n; ++i) {
        for(auto u:yen){
            if(i+u>n)continue;
            dp[i+u]=min(dp[i+u],dp[i]+1);
        }
    }
    cout <<dp[n]<<endl;
    return 0;
}