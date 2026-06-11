#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;
const long long inf = 100000000000LL;

int main() {
  ll a, b, q;
  cin >> a >> b >> q;
  vll s(a), t(b);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  s.push_back(-inf);
  s.push_back(inf);
  t.push_back(-inf);
  t.push_back(inf);
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  vll ret;
  rep(i,q) {
    ll x;
    cin >> x;
    ll sl, sr, tl, tr;
    sr = s[upper_bound(s.begin(),s.end(),x)-s.begin()];
    sl = s[upper_bound(s.begin(),s.end(),x)-s.begin()-1];
    tr = t[upper_bound(t.begin(),t.end(),x)-t.begin()];
    tl = t[upper_bound(t.begin(),t.end(),x)-t.begin()-1];
    ll ans = 100000000000LL;
    ans = min(ans,min((x-sl)+(tr-sl),(tr-x)+(tr-sl)));
    ans = min(ans,min((x-tl)+(sr-tl),(sr-x)+(sr-tl)));
    ans = min(ans,max((sr-x),(tr-x)));
    ans = min(ans,max((x-sl),(x-tl)));
    ret.push_back(ans);
  }
  rep(i,ret.size()) cout << ret[i] << endl;
  return 0;
}