#include<bits/stdc++.h>
using namespace std;

int main()
{
  int D,N;scanf("%d %d",&D,&N);
  if(N==100)N++;
  printf("%d",(int)pow(100,D)*N);
}