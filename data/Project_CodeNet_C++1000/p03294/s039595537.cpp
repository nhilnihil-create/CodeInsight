#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N];int ans=0;
  for(int i=0;i<N;i++){scanf("%d ",&a[i]);a[i]--;ans+=a[i];}
  printf("%d\n",ans);
}