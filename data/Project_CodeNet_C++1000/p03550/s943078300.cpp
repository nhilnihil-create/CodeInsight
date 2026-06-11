#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    int N,Z,W;cin>>N>>Z>>W;
    int a[2010];
    for(int i=0;i<N;i++)cin>>a[i];
    
    //カードがi枚、手番がjから最善を尽くした時のスコア
    int dp[2010][2];
    dp[1][0]=dp[1][1]=abs(a[N-1]-a[N-2]);
    for(int i=2;i<N;i++){
        dp[i][0]=abs(a[N-i-1]-a[N-1]);
        dp[i][1]=abs(a[N-i-1]-a[N-1]);
        for(int j=1;j<i;j++){
            dp[i][0]=max(dp[i][0],dp[j][1]);
            dp[i][1]=min(dp[i][1],dp[j][0]);
        }
    }
    dp[N][0]=abs(W-a[N-1]);
    for(int j=1;j<N;j++)
        dp[N][0]=max(dp[N][0],dp[j][1]);
    cout<<dp[N][0]<<endl;
    return 0;
}