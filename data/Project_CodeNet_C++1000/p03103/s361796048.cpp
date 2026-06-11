#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long N,M,ans=0;scanf("%lld %lld",&N,&M);
  priority_queue<pair<int,int>> AB;
  for(int A,B,i=0;i<N;i++)
  {
    scanf("%d %d",&A,&B);
    AB.push(make_pair(0-A,0-B));
  }
  while(M!=0)
  {
    long long A=0-AB.top().first,B=0-AB.top().second;
    AB.pop();
    if(M-B<0)ans+=A*M,M=0;
    else ans+=A*B,M-=B;
  }
  printf("%lld",ans);
}