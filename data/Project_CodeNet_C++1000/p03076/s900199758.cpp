#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){
  ll ans = 0;
  vector<ll> o(5);
  rep(i,5) {
    cin >> o[i];
  }
  ll min = 10;
  ll id = 0;
  rep(i,5){
    if(o[i]%10==0) continue;
    if(o[i]%10<min){
      id = i;
      min = o[i]%10;
    }
  }

  rep(i,5){
    if(i==id){
      ans += o[i];
      continue;
    }else if(o[i]%10==0){
      ans += o[i];
    }else{
      ans += (o[i]/10+1)*10;
    }
  }

  cout << ans << endl;

  return 0;
} 

