#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n;
  int u;
  cin >> n;
  int x[n],y[n],h[n];
  rep(i,n){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i]>0)u=i;
  }
  swap(x[0],x[u]);
  swap(y[0],y[u]);
  swap(h[0],h[u]);
  int ansx,ansy,ansh;
  rep(i,101){
    rep(j,101){
      int p=0;
      int hh=h[0]+abs(x[0]-i)+abs(y[0]-j);
      rep(l,n-1){
        if(max(0,hh-abs(x[l+1]-i)-abs(y[l+1]-j))!=h[l+1]){
          p++;
          break;
        }
      }
      if(p)continue;
      ansx=i;
      ansy=j;
      ansh=hh;
    }
  }
  cout << ansx << " " << ansy << " " << ansh << endl;
}
