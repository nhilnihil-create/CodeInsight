#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
int main(){
  ll n,k; cin >> n >> k;
  ll sum = 0;
  rep(b,1,n+1){
    sum += (n/b) * max(0LL, b-k);
    sum += max(0LL, n%b+1-k);
  }
  if(k == 0){
    sum -= n;
  }
  cout << sum << endl;
  return 0;

}
