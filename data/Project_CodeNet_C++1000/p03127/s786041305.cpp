#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

ll gcd(ll a, ll b){
// 結合法則も成り立つ
  if(a < b) return gcd(b, a);
  ll r = a % b;
  while(r != 0){
      a = b;
      b = r;
      r = a % b;
  }
  return b;
}

int main(){
  ll N;  cin >> N;
  VL a(N);  rep(i,0,N) cin >> a[i];
  
  ll g = a[0];
  rep(i,1,N) g = gcd(g, a[i]); 

  ll ans = g;
  cout << ans << endl;
  return 0;
}