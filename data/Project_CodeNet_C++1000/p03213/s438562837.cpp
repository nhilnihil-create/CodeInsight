#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<int> k(101,0);
  if(n<=9){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n-1){
    int y=i+2;
    int u=2;
    while(y>1){
      while(y%u==0){
        y/=u;
        k[u]++;
      }
      u++;
    }
  }
  int ans=0;
  int ka=0,kb=0,kc=0,kd=0,ke=0;
  rep(i,99){
    int w=i+2;
    if(k[w]>=2)ka++;
    if(k[w]>=4)kb++;
    if(k[w]>=14)kc++;
    if(k[w]>=24)kd++;
    if(k[w]>=74)ke++;
  }
  //cout << ka << kb << kc << kd << ke << endl;
  ans+=(ka-2)*kb*(kb-1)/2+(ka-1)*kd+ke+(kb-1)*kc;
  cout << ans << endl;
}
