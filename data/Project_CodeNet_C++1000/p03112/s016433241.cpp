#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B,Q;
  cin >> A >> B >> Q;
  vector<ll> s;
  vector<ll> t;
  s.push_back((-1) * (Mod) * (Mod));
  t.push_back((-1) * (Mod) * (Mod));
  for (int i = 0; i < A; i++) {
    ll a;
    cin >> a;
    s.push_back(a);
  } 
  for (int i = 0; i < B; i++) {
    ll b;
    cin >> b;
    t.push_back(b);
  }
  s.push_back((Mod) * (Mod));
  t.push_back((Mod) * (Mod));
  for (int i = 0; i < Q; i++) {
    ll x;
    cin >> x;
    auto itr1 = lower_bound(s.begin(),s.end(),x);
    auto itr2 = prev(itr1,1);
    auto itr3 = lower_bound(t.begin(),t.end(),x);
    auto itr4 = prev(itr3,1);
    ll ans = Mod * Mod;
    ans = min(ans, max(*itr1,*itr3) - x);
    ans = min(ans, x - min(*itr2,*itr4));
    ans = min(ans, ((*itr3 - x) * 2) + (x - *itr2));
    ans = min(ans, ((*itr1 - x) * 2) + (x - *itr4));
    ans = min(ans, ((x - *itr2) * 2) + (*itr3 - x));
    ans = min(ans, ((x - *itr4) * 2) + (*itr1 - x));
    cout << ans << endl;
  }
  return 0;
}