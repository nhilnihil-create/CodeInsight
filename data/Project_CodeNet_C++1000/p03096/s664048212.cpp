#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std; using ll=long long; const int m=1e9+7; using P=pair<int,int>;
const int mx = 2e5;

int main() {
  int n; cin>>n;
  int c[n]; for(int i=0;i<n;i++) cin>>c[i];
  for(int i=0;i<n;i++) c[i]--;
  int d[mx]; fill(d,d+mx,-1); // 前にあった色iの位置
  int e[n]; fill(e,e+n,-1); // 場所iにつながる前の場所
  for(int i=0;i<n;i++) {
    if (d[c[i]] != -1 && d[c[i]] != i-1) {
      e[i] = d[c[i]];
    }
    d[c[i]] = i;
  }
  int f[n]; f[0]=1;
  for(int i=1;i<n;i++) {
    if (e[i] == -1) f[i] = f[i-1];
    else f[i] = f[i-1] + f[e[i]];
    f[i]%=m;
  }
  cout<<f[n-1]<<endl;
}