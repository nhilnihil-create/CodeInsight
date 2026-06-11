#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#define PIE 3.14159265358979
#define MAX_N 16
#define rep(i,n) for(int i = 0;i < (n);i++)
#define show(x) cout<<(#x)<<":"<<x<<" ";
#define showl(x) cout<<(#x)<<":"<<x<<endl;

using namespace std;
typedef long long ll;
const ll MAX_DP=20005;

int main(){
    int N;
    int w[1005],s[1005];
    ll v[1005];
    ll dp[MAX_DP];
    vector<pair<int,int> > vec;//w+s,index
    
    cin>>N;
    vec.reserve(N);
    rep(i,MAX_DP){dp[i]=-1;}
    dp[0]=0;
    rep(i,N){
        cin>>w[i]>>s[i]>>v[i];
        vec.push_back(make_pair(w[i]+s[i],i));
    }
    sort(vec.begin(),vec.end());
    for(auto iter:vec){
        int i = iter.second;
        for(int j = s[i];j>=0;j--){
            if(dp[j]>=0&&j+w[i]<MAX_DP){
                dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
            }
        }
    }
    ll ans = 0;
    rep(i,MAX_DP){ans = max(dp[i],ans);}
    cout<<ans<<endl;
}
