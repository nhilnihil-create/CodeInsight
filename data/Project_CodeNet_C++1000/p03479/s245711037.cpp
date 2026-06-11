#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans = 0;
  while(x<=y) {
    ans++;
    x *= 2;
  }
  cout << ans << endl;
  return 0;
}