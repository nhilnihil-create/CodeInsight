#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int A[2][N];int low[N],up[N];
  for(int i=0;i<2;i++)for(int j=0;j<N;j++)
  {
    scanf("%d",&A[i][j]);
    if(i==0)up[j]=A[i][j];
    else low[j]=A[i][j];
  }
  for(int i=1;i<N;i++)up[i]+=up[i-1],low[N-i-1]+=low[N-i];
  int ans=0;
  for(int i=0;i<N;i++)ans=max(ans,up[i]+low[i]);
  printf("%d",ans);
}