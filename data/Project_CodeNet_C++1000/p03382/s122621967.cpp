#include<bits/stdc++.h>
using namespace std;
int N; int A[101010];
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d", A+i);
  int X = *max_element(A, A+N);
  int Y = A[0]; if(X==Y) Y = A[1];
  for(int i=1; i<N; ++i)
  {
    if(min(Y, X-Y) < min(X-A[i], A[i])) Y = A[i];
  }  
  printf("%d %d\n", X, Y);
}