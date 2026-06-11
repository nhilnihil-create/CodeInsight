#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,big,ansnum;
int a[100030];

int main()
{
  int i,j,t;
  scanf("%d",&n),ans=-1,big=-1;
  for(i=1;i<=n;i++) 
   {
    scanf("%d",&a[i]);
    if(a[i]>big) big=a[i],j=i;
   }
  for(i=1;i<=n;i++) 
   {
   	if(a[i]==big) continue;
    t=min(a[i],big-a[i]);
    if(t>ans) ans=t,ansnum=a[i];
   }
   printf("%d %d\n",big,ansnum);
}