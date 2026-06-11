#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  vector<ll> s(n+1,0);
  rep(i,n)s[i+1] = s[i]+v[i];
  ll res = 1ll << 60;
  auto bs = [&](int left,int right,ll val,vector<ll> &k,ll g){
    while(right-left > 1){
      int mid = (right+left)/2;
      if(s[mid]-g >= (val+1)/2)right = mid;
      else left = mid;
    }
    if(abs(val-2*(s[right]-g)) <= abs(val-2*(s[left]-g)))k.push_back(s[right]-g),k.push_back(val-s[right]+g);
    else k.push_back(s[left]-g),k.push_back(val-s[left]+g);
  };
  for(int i = 2;i < n-1;i++){
    ll l = s[i],r = s[n]-s[i];
    vector<ll> a;
    bs(1,i,l,a,0);
    bs(i+1,n,r,a,l);
    ll mn = 0;
    rep(g,4)rep(gg,4)if(g != gg)mn = max(mn,abs(a[g]-a[gg]));
    res = min(res,mn);
  }
  cout << res << endl;



  return 0;
}