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

int main() {
  ll n;
  cin >> n;
  vll a(n);
  ll cnt = 0LL;
  ll b = 10000000000LL;
  ll ans = 0LL;
  bool check = true;
  rep(i,n) {
    cin >> a[i];
    if(a[i]==0) check = false;
    ans += abs(a[i]);
    b = min(b,abs(a[i]));
    if(a[i]<0) cnt++;
  }
  if(cnt%2==1 && check) ans -= b*2;
  cout << ans << endl;
  return 0;
}