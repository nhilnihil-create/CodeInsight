#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int getsqrt(_int64 x)
{
  int left,right,mid;
  left=0;right=1100000000;
  while (right-left>1)
  {
    mid=(left+right)/2;
    if ((_int64)mid*mid>=x) right=mid;
    else left=mid;
  }
  return left;
}

int main()
{
  int i,j,q,l,a,b;
  _int64 tmp,p,tot;
  scanf("%d",&q);
  for (l=0;l<q;l++)
  {
    scanf("%d%d",&a,&b);
    p=(_int64)a*b;
    tmp=getsqrt(p);
    if (a==b) tot=(a-1)+(a-1);
    else
    if (tmp*(tmp+1)<p)
    {
      tot=tmp*2;
      tot--;
    }
    else
    {
      tot=(tmp-1)*2+1;
      tot--;
    }
    printf("%lld\n",tot);
  }
}