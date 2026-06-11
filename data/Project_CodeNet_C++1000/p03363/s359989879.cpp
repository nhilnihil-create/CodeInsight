#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n,ans=0;
  cin >> n;
  vector<ll>acm(n);
  for(int i=0; i<n; i++){
    ll a;
    cin >> a;
    if(i == 0) acm[i] = a;
    else acm[i] = acm[i-1] + a;
  }
  sort(acm.begin(),acm.end());
  ll now = acm[0],count = 0;
  
  for(int i=0; i<n; i++){
    if(acm[i] == 0){
      ans++;
    }
    if(acm[i] == now){
      count++;
    }else{
      ans += count*(count-1)/2;
      now = acm[i];
      count = 1;
    }
  }
  ans += count*(count-1)/2;
  
  cout << ans << endl;
  
}
