#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

ll gcd(ll a, ll b){
  if(a % b == 0) return b;
  return gcd(b, a%b);
}

int main(){
  ll n,x; cin >> n >> x;
  ll xx; cin >> xx;
  ll ans = abs(xx - x);
  for(int i = 1; i < n; i++){
    cin >> xx;
    ans = gcd(ans, abs(xx - x));
  }
  cout << ans << endl;
  return 0;
}
