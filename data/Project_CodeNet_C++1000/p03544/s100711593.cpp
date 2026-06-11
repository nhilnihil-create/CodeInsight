#include <cstdio>
typedef long long ll;
int N ;
ll L[87];
int main ()
{
  scanf ("%d" ,&N);
  L[0]=2LL , L[1]= 1LL;
  for (int i = 2; i <= N ; i++) {
    L[i]= L[i-2] + L[i-1];
  }
  printf ("%lld\n " , L[N]);
}