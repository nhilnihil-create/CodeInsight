#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()	
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000000;
typedef pair<int,int> P;
int dp[200010];//dp[i]:=[0,i]の部分文字列の中の回文分割の最小値
int co[1<<26];
int main(){
    string s;cin>>s;
    int n=s.length();
    int a=0;
    fill(co,co+(1<<26),INF);
    fill(dp,dp+n+1,INF);
    co[0]=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        a^=(1<<(s[i-1]-'a'));
        dp[i]=min(dp[i],co[a]+1);
        for(int j=0;j<26;j++){
            dp[i]=min(dp[i],co[a^(1<<j)]+1);
        }
        co[a]=min(co[a],dp[i]);
    }
    cout<<dp[n]<<endl;
}