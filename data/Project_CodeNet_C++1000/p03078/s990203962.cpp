#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  for(int i=0;i<x;++i) cin >> a[i];
  for(int i=0;i<y;++i) cin >> b[i];
  for(int i=0;i<z;++i) cin >> c[i];

  ll xy=x*y;
  vector<ll> ab(xy,0);
  int index=0;
  for(int i=0;i<x;++i){
    for(int j=0;j<y;++j){
      ll tmp=a[i]+b[j];
      ab.push_back(tmp);
    }
  }
  sort(ab.rbegin(),ab.rend());
  sort(c.rbegin(),c.rend());
  vector<ll> ans(k*k,0);
  ll cal=min(k,xy);
  ll cal2=min(z,k);
  for(int i=0;i<cal;++i){
    for(int j=0;j<cal2;++j){
      ll tmp=ab[i]+c[j];
      ans.push_back(tmp);
      //cout << tmp << endl;
    }
  }
  sort(ans.rbegin(),ans.rend());
  for(int i=0;i<k;++i) cout << ans[i] << endl;

  return 0;
}
