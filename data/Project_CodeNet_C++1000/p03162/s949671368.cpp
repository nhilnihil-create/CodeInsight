#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
const int INF = 1e9 + 7;
     
int main(){
      IOS;
      int N;
      cin>>N;
      int A[N], B[N], C[N], dp[N][3];
      for(int i=0;i<N;i++){
            cin>>A[i]>>B[i]>>C[i];
      }
      dp[0][0] = A[0];
      dp[0][1] = B[0];
      dp[0][2] = C[0];
      for(int i=1;i<N;i++){
            dp[i][0] = A[i] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = B[i] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = C[i] + max(dp[i-1][0], dp[i-1][1]);
      }
      int mex = INT_MIN;
      if(mex < dp[N-1][0])
            mex = dp[N-1][0];
      if(mex < dp[N-1][1])
            mex = dp[N-1][1];
      if(mex < dp[N-1][2])
            mex = dp[N-1][2];
      cout<<mex;
      return 0;
}