#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PLL = pair<ll,ll>;
const int INF = 1000000001;
const int MOD = 1000000007;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  ll n, h;
  cin >> n >> h;
  priority_queue<ll> a; 
  priority_queue<ll> b;
  rep(i, n){
    int t1, t2;
    cin >> t1 >> t2;
    a.push(t1);
    b.push(t2);
  }

  ll ans = 0;
  ll mx_a = a.top();
  while(!b.empty()){
    ll cur_b = b.top();
    b.pop();
    if(mx_a < cur_b){
      h -= cur_b;
      ans++;
    }
    if(h <= 0){
      break;
    }
  }

  if(h > 0){
    ans += (h + mx_a - 1) / mx_a;
  }

  cout << ans << endl;
  return 0;
}
