#include<bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define tr(container,it) \
for(auto it=container.begin();it!=container.end();++it)
typedef long long ll ; 
typedef vector<int> vi;
#define mod 1000000007 


int main()
{
 //freopen("input.txt","r",stdin);
 //  ios::sync_with_stdio(0);
// cin.tie(0);
int h,w;
cin>>h>>w;
vector<string> v(h);
for(int i=0;i<h;++i)
cin>>v[i];
vector<vector<int>>dp(h+1,vector<int>(w+1));
dp[0][1]=1;

for(int i=1;i<=h;++i){
    for(int j=1;j<=w;++j){
        if(v[i-1][j-1]=='#'){
            dp[i][j]=0;
            continue;
        }
        dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
    }
}
cout<<dp[h][w];
    return 0;
}