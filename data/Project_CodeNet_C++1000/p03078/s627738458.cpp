#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 30000000001;

int main(){
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> ax(x), by(y), cz(z);
  for(int i=0; i<x; ++i) cin >> ax[i];
  for(int i=0; i<y; ++i) cin >> by[i];
  for(int i=0; i<z; ++i) cin >> cz[i];
  sort(ax.rbegin(),ax.rend());
  sort(by.rbegin(),by.rend());
  sort(cz.rbegin(),cz.rend());
  vector<ll> ans;
  for(int i1=0; i1<x; ++i1){
    if(i1+1 > k) break;
    for(int i2=0; i2<y; ++i2){
      if((i1+1)*(i2+1) > k) break;
      for(int i3=0; i3<z; ++i3){
        if((i1+1)*(i2+1)*(i3+1) > k) break;
        ans.push_back(ax[i1] +by[i2] +cz[i3]);
      }
    }
  }
  sort(ans.rbegin(),ans.rend());
  for(int i=0; i<k; ++i){
    printf("%lld\n",ans[i]);
  }
}