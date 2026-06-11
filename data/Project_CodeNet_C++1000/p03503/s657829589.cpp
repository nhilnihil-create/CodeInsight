#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,i,j,b = 1,ans = -100000000000,now;cin >> n;
  long long f[n][10],p[n][11];
  for(i=0;i<n;i++){
    for(j=0;j<10;j++) cin >> f[i][j];
  }
  for(i=0;i<n;i++){
    for(j=0;j<11;j++) cin >> p[i][j];
  }
  while(b<1024){
    long long s[n] = {};
    for(i=0;i<10;i++){
      if(b&(1<<i)){
        for(j=0;j<n;j++) s[j] += f[j][i];
      }
    }
    now = 0;
    for(i=0;i<n;i++) now += p[i][s[i]];
    ans = max(ans,now);
    b++;
  }
  cout << ans << "\n";
}