#include<bits/stdc++.h>
using namespace std;

int main()
{
int N;scanf("%d",&N);
int D,X;scanf("%d %d",&D,&X);
int ans=0;
vector<int> A(N);for(int i=0;i<N;i++)scanf("%d\n",&A[i]);
for(int i=0;i<N;i++)
{
  int d=D;d--;
  ans+=d/A[i]+1;
}
ans+=X;
printf("%d\n",ans);
}