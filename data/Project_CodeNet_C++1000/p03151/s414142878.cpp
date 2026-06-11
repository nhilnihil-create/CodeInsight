#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main() {
  ll n;
  cin >> n;
  vl a(n), b(n);
  ll as=0, bs=0;
  rep(i, n){
    ll num;
    cin >> num;
    a[i] = num;
    as += num;
  }
  rep(i, n){
    ll num;
    cin >> num;
    b[i] = num;
    bs += num;
  }
  if(as<bs){
    cout << -1 << endl;
    return 0;
  }
  vl plus, minus;
  rep(i, n){
    if(a[i] >= b[i]) plus.push_back(a[i]-b[i]);
    else minus.push_back(b[i]-a[i]);
  }
  ll ans = 0;
  ans += minus.size();
  if(ans == 0){
    cout << 0 << endl;
    return 0;
  }
  ll ms = 0;
  for(auto e : minus) ms += e;
  ll ps = 0;
  sort(all(plus), greater<ll>());
  rep(i, plus.size()){
    ps += plus[i];
    if(ps >= ms){
      ans += i+1;
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}