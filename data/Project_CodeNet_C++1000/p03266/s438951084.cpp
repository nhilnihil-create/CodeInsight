#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll n, k, s;
  in2(n, k);
  if(k % 2 == 1)
    s = (n / k) * (n / k) * (n / k);
  else{
    s = (n / k) * (n / k) * (n / k);
    if(n % k >= k / 2)
      s += (n / k + 1) * (n / k + 1) * (n / k + 1);
    else
      s = 2 * s;
  }
  out(s);
  memi;
}