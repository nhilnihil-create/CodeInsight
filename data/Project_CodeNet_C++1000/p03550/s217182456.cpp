#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    ll z, w, n;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    ll dp[n+1][2];
    for(int i = n-1; i >= 0; --i){
        if(i == 0)dp[i][0] = abs(w-a.back());
        else dp[i][0] = abs(a[i-1]-a.back());
        for(int j = i+1; j < n; ++j)dp[i][0]=max(dp[i][0], dp[j][1]);
 
        if(i == 0)dp[i][1] = abs(z-a.back());
        else dp[i][1] = abs(a[i-1]-a.back());
        for(int j = i+1; j < n; ++j)dp[i][1]=min(dp[i][1], dp[j][0]);
    }
    cout << dp[0][0] << endl;
}