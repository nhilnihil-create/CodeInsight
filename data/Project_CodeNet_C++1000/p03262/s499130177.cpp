#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll gcd(ll a, ll b){return b ? gcd(b, a%b):a;}

int main() {
  ll n, X;
  cin >> n >> X;
  vector<ll>sa(n);
  rep(i,n){
    ll x;
    cin >> x;
    sa[i] = abs(X-x);
  }
  int ans = sa[0];
  for (int i = 0; i < sa.size(); ++i){
    ans = gcd(ans, sa[i]);
  }
  cout << ans << endl;
}