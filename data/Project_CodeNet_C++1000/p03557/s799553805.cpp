#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int A[N],B[N],C[N];long long ans=0;
  for(int i=0;i<N;i++)scanf("%d ",&A[i]);
  for(int i=0;i<N;i++)scanf("%d ",&B[i]);
  for(int i=0;i<N;i++)scanf("%d ",&C[i]);
  sort(A,A+N);sort(B,B+N);sort(C,C+N);
  for(int i=0;i<N;i++)
  {
    ans+=((lower_bound(A,A+N,B[i])-A)*(N-(upper_bound(C,C+N,B[i])-C)));
  }
  printf("%lld",ans);
}
