#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,ans=0; cin>>n>>m;
  int k[11],bulb[11][11],p[11];
  for(int i=0;i<m;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++) cin>>bulb[i][j],bulb[i][j]--;
  }
  for(int i=0;i<m;i++) cin>>p[i];
  for(int ptn=0;ptn<1<<n;ptn++){
    int sum[11]={0};
    bool light=true;
    for(int i=0;i<m;i++){
      for(int j=0;j<k[i];j++){
        if(ptn&1<<bulb[i][j]) sum[i]++;
      }
    }
    for(int i=0;i<m;i++) if(p[i]!=sum[i]%2) light=false;
    if(light) ans++;
  }
  cout<<ans;
}