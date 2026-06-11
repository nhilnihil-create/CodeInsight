#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  string ans="Yes";
  int t[N+1],x[N+1],y[N+1];
  for(int i=1;i<N+1;i++)scanf("%d %d %d",&t[i],&x[i],&y[i]);
  t[0]=0;x[0]=0;y[0]=0;
  for(int i=1;i<N+1;i++)
  {
    if(abs(x[i]-x[i-1])+abs(y[i]-y[i-1])>t[i]-t[i-1])ans="No";
    if((t[i]-t[i-1]-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))%2==1)ans="No";
  }
  cout<<ans<<endl;
}