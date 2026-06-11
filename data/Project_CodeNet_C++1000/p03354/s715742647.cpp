#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> p(n),x(m),y(m);
  rep(i,n){
    cin >> p[i];
    p[i]--;
  }
  vector<int> uf(n);
  rep(i,n)uf[i] = INF;
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
    int rootx = x[i], rooty = y[i], stepx = 0, stepy = 0;
    while(uf[rootx]!=rootx && uf[rootx] != INF){
      stepx++;
      rootx = uf[rootx];
    }
    while(uf[rooty]!=rooty && uf[rooty] != INF){
      stepy++;
      rooty = uf[rooty];
    }
    if(rootx != rooty || (uf[rootx]==INF && uf[rooty]==INF)){
      if(uf[rooty]==INF && uf[rootx]==INF){
        uf[x[i]] = x[i];
        uf[y[i]] = x[i];
      }else if(uf[rooty]!=INF && uf[rootx]==INF){
        uf[x[i]] = rooty;
      }else if(uf[rootx]!=INF && uf[rooty]==INF){
        uf[y[i]] = rootx;
      }else{
        if(stepx>stepy)uf[rooty] = rootx;
        else uf[rootx] = rooty;
      }
    }
  }
  int ans = 0;
  rep(i,n){
    if(p[i]==i){
      ans++;
      continue;
    }
    if(uf[i]==INF || uf[p[i]]==INF)continue;
    int pi = p[i];
    while(uf[pi] != pi)pi = uf[pi];
    int ii = i;
    while(uf[ii] != ii)ii = uf[ii];
    if(pi == ii)ans++;
  }
  cout << ans << endl;
  return 0;
}