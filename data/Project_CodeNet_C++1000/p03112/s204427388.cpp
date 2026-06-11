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
  vll ret;
  rep(i,q) {
    ll x;
    cin >> x;
    ll sl, sr, tl, tr;
    sl = sr = tl = tr = 0LL;
    if(x < s[0]) {
      sr = s[0];
      sl = -inf;
    }
    if(x > s[a-1]) {
      sr = inf;
      sl = s[a-1];
    }
    if(x < t[0]) {
      tr = t[0];
      tl = -inf;
    }
    if(x > t[b-1]) {
      tr = inf;
      tl = t[b-1];
    }
    if(sr == 0LL) sr = s[upper_bound(s.begin(),s.end(),x)-s.begin()];
    if(sl == 0LL) sl = s[upper_bound(s.begin(),s.end(),x)-s.begin()-1];
    if(tr == 0LL) tr = t[upper_bound(t.begin(),t.end(),x)-t.begin()];
    if(tl == 0LL) tl = t[upper_bound(t.begin(),t.end(),x)-t.begin()-1];
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