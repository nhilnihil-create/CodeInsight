#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

ll dsum(ll i){
  st sti = to_string(i);
  ll sum = 0;
  vrep(j, sti) sum += j - '0';
  return sum;
}
int main(){
  ll n;
  cin >> n;
  ll ans = mod;
  rep(i, 1, n){
    ll sum = dsum(i) + dsum(n - i);
    if(sum < ans) ans = sum;
  }
  cout << ans << endl;
}