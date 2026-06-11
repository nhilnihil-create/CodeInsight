#include<bits/stdc++.h>
using namespace std;

int main()
{
int N,M;scanf("%d %d",&N,&M);vector<int> road(N+2,0);
for(int L,R,i=0;i<M;i++)
{
  scanf("%d %d",&L,&R);
  road[L]++;road[R+1]--;
}
int ans=0;
for(int i=1;i<N+2;i++)
{
  road[i]+=road[i-1];
  if(road[i]==M)ans++;
}
printf("%d\n",ans);
}