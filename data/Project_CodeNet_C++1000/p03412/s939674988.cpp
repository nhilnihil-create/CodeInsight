#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int a[N];
int b[N];
int n;

int compute(ll k){
  vector<ll> ai, bi;
  ll mod = 2 * k;
  for(int i = 0 ; i < n; i ++ ){
    ai.push_back(a[i] % mod);
    bi.push_back(b[i] % mod);
  }
  sort(ai.begin(), ai.end());
  sort(bi.begin(), bi.end());
  ll li = k;
  ll ri = 2 * k;
  ll ans = 0;
  ll cl, cr;
  for(auto x : ai){
    cl = lower_bound(bi.begin(), bi.end(), li - x) - bi.begin();
    cr = lower_bound(bi.begin(), bi.end(), ri - x) - bi.begin();
    ans += cr - cl;
  }
  li += mod;
  ri += mod;
  for(auto x : ai){
    cl = lower_bound(bi.begin(), bi.end(), li - x) - bi.begin();
    cr = lower_bound(bi.begin(), bi.end(), ri - x) - bi.begin();
    ans += cr - cl;
  }
  return (ans & 1);
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < n ; i ++ ){
    cin >> b[i];
  }
  ll ans = 0;
  for(int bit = 0; bit < 31 ; bit ++ ){
    ans += compute((1ll << bit)) * (1ll << bit);
  }
  cout << ans << "\n";
  return 0;
}