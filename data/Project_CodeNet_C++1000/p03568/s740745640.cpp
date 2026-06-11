#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int A[N];
  for(int i=0;i<N;i++)scanf("%d ",&A[i]);
  int minus=1;
  for(int i=0;i<N;i++)minus*=(2-A[i]%2);
  printf("%d\n",(int)pow(3,N)-minus);
}