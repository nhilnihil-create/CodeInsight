#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<cmath>
#include<stack>
using namespace std;
int a[100010];
int main()
{
  int a[60000],b[10000],r,m=0,n,i,j,k,l,rmid,lmid;
  cin>>n;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  for(i=2;i<=60000;i++)
  {
      if(!a[i])
      {
          b[m++]=i;
      }
      for(j=0;j<m&&i*b[j]<=60000;j++)
      {
          a[i*b[j]]=1;
          if(i%b[j]==0)
            break;
      }
  }
  i=0;
  while(i<n)
  {
      if(b[i]%10==1)
        cout<<b[i]<<" ";
      else
      {
          n++;
      }
      i++;
  }
  return 0;
}
