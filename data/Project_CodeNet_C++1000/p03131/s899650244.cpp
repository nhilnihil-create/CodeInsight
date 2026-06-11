#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll k, a, b; cin >> k >> a >> b;
  if(b <= a+1){
    cout << 1+k << endl;
    return 0;
  }

  if(k < a+1){
    cout << 1+k << endl;
    return 0;
  }

  ll ans = a;
  k -= a-1;
  ll n = k/2;
  rep(i, 0, n) ans += b-a;
  if(k%2 != 0) ans += 1;

  cout << ans << endl;

  return 0;
}
