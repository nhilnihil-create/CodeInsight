#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,j,ans = 1;scanf("%d%d",&n,&m);
  for(i=1;i*i<=m;i++){
    if(m%i==0){
      j = m/i;
      if(i<n && j<n) continue;
      if(i>=n) ans = max(ans,j);
      else if(j>=n) ans = max(ans,i);
      else ans = max({ans,i,j});
    }
  }
  printf("%d\n",ans);
  return 0;
}