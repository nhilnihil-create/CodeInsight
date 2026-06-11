#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long X,Y;scanf("%lld %lld",&X,&Y);
  int ans=0;
  while(X<=Y){ans++;X*=2;}
  printf("%d\n",ans);
}