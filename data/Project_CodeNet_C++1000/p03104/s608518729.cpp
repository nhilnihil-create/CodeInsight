//答え見ました
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll c){
  if (c<=0) return 0;
  c++;
  ll ans = 0;
  for(int i=0; i<50; i++){
    ll loop = (1LL << (i+1));
    ll count=(c/loop)*(loop/2);
    count += max(0LL,(c%loop)-(loop/2));
    
    if(count%2==1) ans+=1LL << i;
  } 
  return ans;
}

int main(){
  ll a,b;
  cin >> a >> b;
  ll ans = calc(b) ^ calc(a-1);
  cout << ans << endl;
}