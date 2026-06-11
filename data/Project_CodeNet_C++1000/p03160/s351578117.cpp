    #include <bits/stdc++.h>
    using namespace std;
     
    int frog1(int* s, int n){
      int dp[100006];
      dp[0]=dp[1] = 0;
      for(int i=2;i<=n;i++){
        int op1 = abs(s[i]-s[i-1]) + dp[i-1];
        int op2 = (i==2)?INT_MAX:abs(s[i]-s[i-2]) + dp[i-2];
        dp[i] = min(op1, op2);
      }
     
      return dp[n];
    }
     
    int main() {
      int a[100005];
      int n;	cin>>n;
      for(int i=1;i<=n;i++){
        cin>>a[i];
      }
      cout<<frog1(a,n);
      return 0;
    }