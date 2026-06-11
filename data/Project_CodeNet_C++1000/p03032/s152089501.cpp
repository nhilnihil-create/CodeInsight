#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];

  ll limit = min(n,k);
  ll ans = -100000000000000;
  for(ll i = 1; i <= limit; i++){
    // cout << i << endl;
    for(ll a = 0; a <= i; a++){
      ll sum = 0;
      ll b = i-a;
      vector<ll> add;
      rep(j,a){
        sum += v[j];
        add.push_back(v[j]);
      }
      rep(j,b){
        sum += v[n-1-j];
        add.push_back(v[n-1-j]);
      }
      sort(add.begin(),add.end());

      for(ll j = 0; j < k-i;j++){
        if(add[j]>=0){
          break;
        }
        sum -= add[j];
      }
      ans = max(ans, sum);
      
    }
  }
  cout << ans << endl;

  return 0;
}