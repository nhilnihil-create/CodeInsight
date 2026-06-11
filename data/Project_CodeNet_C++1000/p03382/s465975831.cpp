#include<bits/stdc++.h>

using namespace std;

int data[100005];

int main()
{
  int n,mx=0,ans=INT_MAX,mxid=-1;
  double tmp;

  scanf("%d",&n);
  for(int c=0;c<n;c++)
  {
    scanf("%d",&data[c]);
    if (data[c]>mx)
    {
      mx=data[c];
      mxid=c;
    }
  }
  tmp=(double)mx/2;
  for(int c=0;c<n;c++)
  {
    if (mxid==c)continue;
    if (abs(data[c]-tmp)<abs(ans-tmp))ans=data[c];
  }
  printf("%d %d\n",mx,ans);
}
