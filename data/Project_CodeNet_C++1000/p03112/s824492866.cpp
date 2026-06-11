#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll a, b, q;
  cin >> a >> b >> q;
  
  vector<ll> s(a + 2), t(b + 2);
  s[0] = t[0] = -INF;
  s[a + 1] = INF;
  t[b + 1] = INF;
  for (int i = 0; i < a; i++){
    cin >> s[i + 1];
  }
  for (int i = 0; i < b; i++){
    cin >> t[i + 1];
  }


  for (int i = 0; i < q; i++){
    ll x;
    cin >> x;
    
    ll A = s[lower_bound(s.begin(), s.end(), x) - s.begin()];
    ll B = t[lower_bound(t.begin(), t.end(), x) - t.begin()];
    ll C, D;
    if (A == x)
      C = x;
    else 
      C = s[lower_bound(s.begin(), s.end(), x) - s.begin() - 1];
    if (B == x)
      D = x;
    else 
      D = t[lower_bound(t.begin(), t.end(), x) - t.begin() - 1];
    cout << min(max(A, B) - x, min(x - min(C, D), min(B - C + min(B - x, x - C), A - D + min(A - x, x - D)))) << endl;
  }
  
  

  return 0;
}
