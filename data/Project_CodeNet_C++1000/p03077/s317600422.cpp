#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  ll n;
  cin >> n;
  vector<ll> a(5);
  rep(i,5) cin >> a[i];

  ll mn = 1e16;
  rep(i,5) mn = min(mn,a[i]);

  if(n <= mn){
    cout << 5 << endl;
    return 0;
  }

  ll cnt;
  if(n%mn == 0)  cnt = n/mn;
  else  cnt = n/mn+1;
  
  ll ans = 4 + cnt;
  cout << ans << endl;

  
}
