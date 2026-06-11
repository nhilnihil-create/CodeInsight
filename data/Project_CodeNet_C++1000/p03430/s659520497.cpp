#include <bits/stdc++.h>
int f[305][305][305],n,k;
char s[305];
inline int dfs(int l,int r,int k){
  if (l==r) return 1; if (l>r) return 0;
  if (f[l][r][k]) return f[l][r][k];
  f[l][r][k]=std::max(dfs(l+1,r,k),dfs(l,r-1,k));
  if (s[l]==s[r]) f[l][r][k]=std::max(f[l][r][k],dfs(l+1,r-1,k)+2);
  else if (k) f[l][r][k]=std::max(f[l][r][k],dfs(l+1,r-1,k-1)+2);
  return f[l][r][k];
}
int main(){
  std::cin>>s>>k,n=strlen(s);
  std::cout<<dfs(0,n-1,k); return 0;
}
