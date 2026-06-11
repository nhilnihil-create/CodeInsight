#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  int w = a[n-1];
  int ng=-1, ok=w/2;
  while(ok - ng > 1) {
    int r = (ng+ok)/2;
    if (w-r > r+1) ng=r;
    else ok=r;
  }
  int an = -1, df = 1e9;
  for(int i=0;i<n;i++) {
    int s;
    if (w % 2 == 1) {
      // 1 5 10 10 5 1
      if (w/2 >= a[i]) s=w/2-a[i];
      else s=a[i]-(w/2+1);
    } else {
      if (w/2 >= a[i]) s=w/2-a[i];
      else s=a[i]-w/2;
    }
    if (df>s) an=a[i], df=s;
  }
  cout<<w<<" "<<an<<endl;
}