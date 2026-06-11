#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,T,A;scanf("%d\n%d %d",&N,&T,&A);
  int H[N];
  for(int i=0;i<N;i++)scanf("%d ",&H[i]);
  double AA=abs(A-T+H[0]*0.006);
  int ans=1;
  for(int i=1;i<N;i++)
  {
    if(AA>abs((double)A-T+H[i]*0.006)){AA=abs(A-T+H[i]*0.006);ans=i+1;}
  }
  printf("%d",ans);
}