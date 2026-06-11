#include <bits/stdc++.h>

using namespace std;

int a,b; 
int c[100010],d[100010],e[100010];
int f[200010]; 
int g[200010]; 
int main() {
  cin >> a>>b;
  for(int i=0;i<a;i++)
    cin >> c[i] >> d[i] >> e[i];
  
  for(int i=1;i<=b;i++) { 
    for(int j=0;j<200010;j++)
      g[j]=0; 
             for(int j=0;j<a;j++)
                           
          if(e[j]==i) g[c[j]*2-1]++,g[d[j]*2]--; 
    
    for(int j=1;j<200010;j++)g[j]+=g[j-1]; 
    
    for(int j=0;j<200010;j++)if(g[j]>0)f[j]++;
  } 
  int ans=0;
  
  for(int j=0;j<200010;j++){
    ans = max(ans,f[j]);
  }
  
  cout << ans << endl;
  
}