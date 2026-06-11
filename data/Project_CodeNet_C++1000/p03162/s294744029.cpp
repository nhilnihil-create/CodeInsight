#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> a(n),b(n),c(n);
  for (int i=0;i<n;i++)
  {
    int p,q,r;
    cin>>p>>q>>r;
    a[i]=p;
    b[i]=q;
    c[i]=r;
  }
  vector<int> M(3),dp(3);
  dp[0]=a[0];
  dp[1]=b[0];
  dp[2]=c[0];
  for (int i=1;i<n;i++)
  {
    M[0]=max(dp[1]+a[i],dp[2]+a[i]);
    M[1]=max(dp[0]+b[i],dp[2]+b[i]);
    M[2]=max(dp[0]+c[i],dp[1]+c[i]);
    dp=M;
  }
  cout<<max(dp[0],max(dp[1],dp[2]));
  
}