#include<bits/stdc++.h>
using namespace std;

double mem[301][301][301];

double rec(int n,int one, int two, int three)
{
  if(one==0&&two==0&&three==0)
    return 0;
  if(mem[one][two][three]!=0)
    return mem[one][two][three];
  double ans=n;
  if(one>0)
  	ans+=one*rec(n,one-1,two,three);
  if(two>0)
    ans+=two*rec(n,one+1,two-1,three);
  if(three>0)
    ans+=three*rec(n,one,two+1,three-1);
  ans=(double)ans/(one+two+three);
  mem[one][two][three]=ans;
  return ans;
    
}

int main(){
  int n;
  cin>>n;
  int a[n];
  int one=0,two=0,three=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]==1)
      one++;
    if(a[i]==2)
       two++;
    if(a[i]==3)
       three++;
  }
  /*double dp[310][310][310];
  dp[0][0][0]=0;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      for(int k=0;k<=n;k++)
      {
        double curr=n;
        if(k>0)
          curr+=k*dp[k-1][j][i];
        if(j>0)
          curr+=j*dp[k+1][j-1][i];
        if(i>0)
          curr+=i*dp[k][j+1][i-1];
        if((i+j+k)!=0)
       	  dp[k][j][i]=(double)curr/(i+j+k);
      }
    }
  }
  cout<<fixed<<setprecision(10)<<dp[one][two][three];*/
  
  
  memset(mem,0,sizeof(mem));
  cout<<fixed<<setprecision(10)<<rec(n,one,two,three);
  
  
}