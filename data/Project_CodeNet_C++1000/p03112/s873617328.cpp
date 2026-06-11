#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

  ll a,b,Q;
  cin >> a >> b >> Q;
  vector<ll> s(a);
  vector<ll> t(b);
  rep(i,a){
    cin >> s[i];
  }
  rep(i,b){
    cin >> t[i];
  }

  sort(s.begin(), s.end(), less<ll>());
  sort(t.begin(), t.end(), less<ll>());

  rep(i,Q){
    ll x;
    cin >> x;

    ll sl=0,sr=0;
    ll tl=0,tr=0;

    sr = distance(s.begin(),lower_bound(s.begin(), s.end(), x));
    if(sr!=0) sl = sr-1;
    if(sl==a-1) sr = sl;
    tr = distance(t.begin(),lower_bound(t.begin(), t.end(), x));
    if(tr!=0) tl = tr-1;
    if(tl==b-1) tr = tl;

    // cout << s[sl] << " " << s[sr] << " " << t[tl] << " " << t[tr] << endl;
    vector<ll> ans;
    if(s[sr]>=x&&t[tr]>=x) ans.push_back(max(s[sr],t[tr])-x);
    if(s[sl]<=x&&t[tl]<=x) ans.push_back(x-min(s[sl],t[tl]));
    if(s[sr]>=x&&t[tl]<=x) ans.push_back(min(s[sr]-x,x-t[tl])*2 + max(s[sr]-x,x-t[tl]));
    if(s[sl]<=x&&t[tr]>=x) ans.push_back(min(t[tr]-x,x-s[sl])*2 + max(t[tr]-x,x-s[sl]));
    
    sort(ans.begin(), ans.end(), less<ll>());
    cout << ans[0] << endl;
  }

  return 0;
} 