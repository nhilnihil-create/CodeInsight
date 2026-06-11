#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n, k;
  cin >> n >> k;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = INF;
  for(int i = 0; i < n; ++i){
    if(i + k - 1 < n){
      ans = min(ans, x[i+k-1] - x[i] + min(abs(x[i+k-1]), abs(x[i])));
    }
  }

  cout << ans << endl;

	return 0;
}

