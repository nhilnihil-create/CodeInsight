#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
int main()
{
  scanf("%lld",&n);
  for(int i=1; i<=n; i++)
    scanf("%lld",&a[i]);
  long long l=1,r=1,sumx=a[1],sum=a[1];
  for(int i=1; i<=n; i++)
  {
    while((sumx==sum)&&r<=n)
    {
      sum+=a[r+1];
      sumx^=a[r+1];
      r++;
    }
    ans+=(r-1)-l+1;
    sumx^=a[l];
    sum-=a[l];
    l++;
    if(r<l)
      r=l;
  }
  cout<<ans<<"\n";
  return 0;
}
//freopen(" .in","r",stdin);//输入
//freopen(" .out","w",stdout);//输出
