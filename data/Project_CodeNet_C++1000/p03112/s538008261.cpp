#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001;

int main(){
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> va(a), vb(b);
  for(int i=0; i<a; ++i) cin >> va[i];
  for(int i=0; i<b; ++i) cin >> vb[i];
  for(int i=0; i<q; ++i){
    ll x;
    cin >> x;
    ll ans = INF;
    auto it1 = lower_bound(va.begin(),va.end(),x);
    auto it2 = lower_bound(vb.begin(),vb.end(),*it1);
    if(it1 != va.end()){
      if(it2 != vb.end()) ans = min(ans, *it2 -x); 
      --it2;
      if(it2 != vb.begin()-1) ans = min(ans, *it1 *2 -x -*it2);
    }
    if(it1 != va.begin()){
      --it1; 
      it2 = lower_bound(vb.begin(),vb.end(),*it1);
      if(it2 != vb.end()) ans = min(ans, *it2 +x -*it1 *2);
      --it2;
      if(it2 != vb.begin()-1) ans = min(ans, x -*it2);
    }
    it1 = lower_bound(vb.begin(),vb.end(),x);
    it2 = lower_bound(va.begin(),va.end(),*it1);
    if(it1 != vb.end()){
      if(it2 != va.end()) ans = min(ans,*it2 -x);
      --it2;
      if(it2 != va.begin()-1) ans = min(ans, *it1 *2 -x -*it2);
    }
    if(it1 != vb.begin()){
      --it1;
      it2 = lower_bound(va.begin(),va.end(),*it1);
      if(it2 != va.end()) ans = min(ans, *it2 +x -*it1 *2);
      --it2;
      if(it2 != va.begin()-1) ans = min(ans, x -*it2);
    }
    printf("%lld\n", ans);
  }
}