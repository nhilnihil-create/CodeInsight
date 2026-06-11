
#include <bits/stdc++.h>
 
using namespace std;
int main()
{
  int n;
  long int h,w;
  scanf("%d%ld%ld",&n,&h,&w);
  long int a[n],b[n];
  int i,cnt=0;
  for(i=0;i<n;++i)
  {
    scanf("%ld%ld",&a[i],&b[i]);
    if(a[i]>=h && b[i]>=w)
         cnt++;
  }
  
  printf("%d",cnt);
}