#include<bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,C;long long K;scanf("%d %d %d %lld",&A,&B,&C,&K);
  if(K%2==0)printf("%d",A-B);
  else printf("%d",B-A);
}