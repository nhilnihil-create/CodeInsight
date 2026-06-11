#include<bits/stdc++.h>
using namespace std;
void check(bool p)
{
  if(!p)
  {
    puts("-1");
    exit(0);
  }
}
const int B = 35;
int N;
long long X[1010];
long long Y[1010];
long long XpY[1010];
long long XmY[1010];
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; ++i)
  {
    scanf("%lld%lld", X+i, Y+i);
    XpY[i] = X[i]+Y[i];
    XmY[i] = X[i]-Y[i];
  }
  vector<long long> W;
  if(XpY[0]%2 == 0)
  {
    W.push_back(1LL);
    for(int i=0; i<N; ++i)
    {
      XpY[i]++; XmY[i]++;
    }
  }
  for(int i=0; i<N; ++i) 
      check(XpY[i]%2 != 0);
  for(int i=0; i<B; ++i) W.push_back(1LL<<i);
  for(int i=0; i<N; ++i)
  {
    XpY[i] += (1LL<<B)-1;
    XmY[i] += (1LL<<B)-1;
    XpY[i] /= 2;
    XmY[i] /= 2;
  }
  printf("%d\n", (int)W.size());
  for(auto x: W) printf("%lld ", x);
  puts("");
  for(int i=0; i<N; ++i)
  {
    if(W.size() == B+1) putchar('L');
    for(int j=0; j<B; ++j)
    {
      bool p = (XpY[i]&(1LL<<j)) != 0;
      bool m = (XmY[i]&(1LL<<j)) != 0;
      if(!p && !m) putchar('L');
      if( p &&  m) putchar('R');
      if(!p &&  m) putchar('D');
      if( p && !m) putchar('U');
    }
    puts("");
  }
  return 0;
  
}