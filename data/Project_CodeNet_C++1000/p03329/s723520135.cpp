#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

int main(){
    int n;cin>>n;
    int dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=1;i+j<=n;j*=6){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
        for(int j=1;i+j<=n;j*=9){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}