#include <bits/stdc++.h>
#define ll long long
int v[10];
int ans = 1490390;
int n,A,B,C;
void dfs(int a,int b,int c,int i,int unite){
  if(v[i] == -1){
    if(a == 0 || b == 0 || c == 0)return;
    std::vector<int>tmp(3);
    tmp[0] = a,tmp[1] = b,tmp[2] = c;
    sort(tmp.rbegin(),tmp.rend());
    a = tmp[0],b = tmp[1],c = tmp[2];
    int cost = 0;
    cost = abs(a - A) + abs(b - B) + abs(c - C) + unite;
    ans = std::min(ans,cost);
    return;
  }
  if(a == 0)dfs(a + v[i],b,c,i + 1,unite);
  else dfs(a + v[i],b,c,i + 1,unite + 10);
  if(b == 0)dfs(a ,b + v[i],c,i + 1,unite);
  else dfs(a ,b + v[i],c,i + 1,unite + 10);
  if(c == 0)dfs(a,b,c + v[i],i + 1,unite);
  else dfs(a,b,c + v[i],i + 1,unite + 10);
  dfs(a,b,c,i + 1,unite);
}
int main(){
  std::cin >> n >> A >> B >> C;
  for(int i = 0; i < n; i++)std::cin >> v[i];
  v[n] = -1;
  dfs(0,0,0,0,0);
  std::cout << ans << std::endl;
}
