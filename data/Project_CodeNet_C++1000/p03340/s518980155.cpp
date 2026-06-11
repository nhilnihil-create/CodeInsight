#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=200010;
long long a[N];

int main()
{
  int n;
  while(scanf("%d",&n)==1)
  {
    long long ret=0;
    for(int i=1; i<=n; i++)
      scanf("%d",&a[i]);
    int j=0;
    long long sum1=0,sum2=0;
    for(int i=1; i<=n; i++)
    {
      while(j+1<=n&&(sum1+a[j+1])==(sum2^a[j+1]))
      {
        sum1+=a[j+1];
        sum2=sum2^a[j+1];
        j++;
      }
      if(sum1==sum2)
        ret+=j-i+1;
      sum1-=a[i];
      sum2=sum2^a[i];
    }
    printf("%lld\n",ret);
  }
  return 0;
}
