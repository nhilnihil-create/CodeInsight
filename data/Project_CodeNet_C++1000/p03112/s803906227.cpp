#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll inf = 1e18;
  int a,b,q;
  cin >> a >> b >> q;
  vector<ll>s(a);
  vector<ll>t(b);
  rep(i,0,a) cin >> s[i];
  rep(i,0,b) cin >> t[i];
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  
  rep(i,0,q){
    ll x;
    cin >> x;
    ll pos1 = lower_bound(s.begin(),s.end(),x)-s.begin();
    ll pos2 = lower_bound(t.begin(),t.end(),x)-t.begin();
    vector<ll>s1,t1;
    if(pos1 != 0) s1.push_back(s[pos1-1]);
    if(pos1 != a) s1.push_back(s[pos1]);
    if(pos2 != 0) t1.push_back(t[pos2-1]);
    if(pos2 != b) t1.push_back(t[pos2]);
    ll ans = inf;
    rep(i,0,s1.size()) rep(j,0,t1.size()){
      ans = min(ans,abs(x-s1[i])+abs(s1[i]-t1[j]));
      ans = min(ans,abs(x-t1[j])+abs(s1[i]-t1[j]));
    }
    cout << ans << endl;
  }
}