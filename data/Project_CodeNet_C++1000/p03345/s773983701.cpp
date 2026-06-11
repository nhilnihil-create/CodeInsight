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
	ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll ans;
  if(k % 2 == 0){
    ans = a - b;
  }
  else{
    ans = b - a;
  }

  if(abs(ans) > 1e18){
    cout << "Unfair" << endl;
  }
  else{
    cout << ans << endl;
  }
  return 0;
}

