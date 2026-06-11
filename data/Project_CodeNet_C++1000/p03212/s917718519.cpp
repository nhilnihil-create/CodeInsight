#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int i,j,k,N,M,X,ans;

void dfs(int s,int t,int u, long long  X)
{
  if(X>N) return;
  else if(s>0 && t>0 && u>0) ans++;
  
  X*=10;
  X+=3;
  s++;
  dfs(s,t,u,X);
  X-=3;
  s--;
  
  X+=5;
  t++;
  dfs(s,t,u,X);
  X-=5;
  t--;

  X+=7;
  u++;
  dfs(s,t,u,X);
  X-=7;
  u--;
  
}


int main()
{
  cin>>N;
  ans=0;
  dfs(0,0,0,0);
  
  
  
  cout <<ans;
  
  
  
  
}