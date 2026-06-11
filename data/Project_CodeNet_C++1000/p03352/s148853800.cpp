#include<bits/stdc++.h>
using namespace std;

int main()
{
  int X;scanf("%d",&X);vector<int> prime(0);
  bool pri[X+1];fill(pri,pri+X+1,false);pri[1]=true;
  for(int i=2;i<X+1;i++)
  {
    int x=i;
    if(pri[i])continue;
    bool check=false;
    while(x*i<=X){pri[x*i]=true;x*=i;check=true;}
    if(!check)pri[i]=false;
  }
  for(int i=X;i>0;i--)if(pri[i]){printf("%d",i);return 0;}
}