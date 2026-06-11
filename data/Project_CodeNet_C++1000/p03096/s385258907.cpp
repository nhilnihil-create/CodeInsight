#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

#define MOD 1000000007
int main(){
    ll n;
    cin >> n;
    ll c[n+1];
    rep(i, n)cin >> c[i+1];

    ll back[200200] = {};
    ll dp[200200] = {};
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        if(back[c[i]] == 0)dp[i] = dp[i-1];
        else dp[i] = (dp[i-1]+dp[back[c[i]]])%MOD;
        back[c[i]] = i;
        while(c[i+1] == c[i])dp[i+1]=dp[i],i++;
    }
    // rep(i, n+1)cout << dp[i] << ", ";cout << endl;
    cout << dp[n];
    
}