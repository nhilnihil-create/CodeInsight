#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  scanf("%d",&N);
  long long L[87];
  L[0]=2LL;L[1]=1LL;
  for(int i=2;i<=N;i++) L[i]=L[i-2]+L[i-1];
  printf("%lld\n",L[N]);
}