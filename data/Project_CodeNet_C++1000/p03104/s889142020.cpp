#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

ll f(ll a) {
  if(a%2==1) {
    if((a+1)%4==0) return 0LL;
    else return 1LL;
  }
  else {
    if(a%4==0) return a;
    else return a+1;
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll c = f(a-1);
  ll d = f(b);
  ll ans = 0LL;
  ll i = 1LL;
  while(c>0 || d>0) {
    if(c%2 != d%2) ans += i;
    c /= 2;
    d /= 2;
    i *= 2;
  }
  cout << ans << endl;
  return 0;
}