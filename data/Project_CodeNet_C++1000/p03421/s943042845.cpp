#include<bits/stdc++.h>
using namespace std;
int N, A, B;
int main()
{
  scanf("%d%d%d", &N, &A, &B);
  if(N > 1LL*A*B || N < A+B-1){ puts("-1"); return 0;}
  for(int i=B; i>=1; --i) printf("%d ", i);
  //(N-B)/A
  int nex = B+1;
  for(int i=0; i<A-1; ++i)
  {
    int nex2 = nex+(N-B+i)/(A-1);
    for(int j=nex2-1; j>=nex; --j)
      printf("%d ", j);
    nex = nex2;
  }
  return 0;
}