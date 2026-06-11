#include<bits/stdc++.h>
using namespace std;
int solve(int A, int B)
{
  if(A == 1 && B == 1) return 0;
  if(A == B) return 2*(A-1);
  if(abs(A-B)<=2) return A+B-3;
  long long sqrtd = sqrt((long double)(1LL*A*B-1));
  int ans = 2*(sqrtd-1);
  if(A <= sqrtd-1) --ans;
  if(B <= sqrtd-1) --ans;
  if(1LL*sqrtd*(sqrtd+1) < 1LL*A*B && A != sqrtd && A!=sqrtd+1 && B != sqrtd && B != sqrtd+1)
    return ans+2;
  return ans+1;
  
}
int main()
{
  int Q; scanf("%d", &Q);
  while(Q--)
  {
    int A, B; scanf("%d%d", &A, &B);
    printf("%d\n", solve(A, B));
  }
}


