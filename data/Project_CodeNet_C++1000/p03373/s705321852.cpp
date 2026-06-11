#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

int main(){
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = mod;
  rep(i, 0, max(x, y) + 1){
    ll cost =  c * 2 * i + b * max(0ll, y - i) + a * max(0ll, x - i);
    if(ans > cost) ans = cost;
  } 
  cout << ans << endl;
}