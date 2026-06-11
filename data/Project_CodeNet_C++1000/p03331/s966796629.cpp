#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 999999999999999;

int main(){
  ll n;
  cin >> n;
  ll a,ans = INF;
  for(ll i=1;i<n;++i){
    a = n-i;
    string sa = to_string(a);
    string sb = to_string(i);
    ll sum = 0;
    for(char c:sa) sum += c-'0';
    for(char c:sb) sum += c-'0';
    ans = min(ans,sum);
  }
  
  cout << ans << endl;
  return 0;
}