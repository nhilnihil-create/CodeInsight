#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){
  
  ll a,b,Q;
  const ll inf = (1ll << 60);
  cin >> a >> b >> Q;
  vector<ll> s(a+1),t(b+1);
  s[0] = -inf;
  t[0] = -inf;
  for(int i = 1;i <= a;i++)cin >> s[i];
  for(int i = 1;i <= b;i++)cin >> t[i];
  s.push_back(inf);
  t.push_back(inf);

  auto bssl = [&](ll x)-> ll{
    ll left = 0,right = (ll)s.size()-1;
    while(right-left > 1){
      ll mid = (right+left)/2;
      if(s[mid] >= x)right = mid;
      else left = mid;
    }
    return right;
  };
  auto bstl = [&](ll x)-> ll{
    ll left = 0,right = (ll)t.size()-1;
    while(right-left > 1){
      ll mid = (right+left)/2;
      if(t[mid] >= x)right = mid;
      else left = mid;
    }
    return right;
  };
  REP(i,Q){
    ll x;cin >> x;
    ll sl = bssl(x),sm = sl-1,tl = bstl(x),tm = tl-1;
    ll l = max(s[sl],t[tl])-x,m = x-min(s[sm],t[tm]),st = min(abs(t[tl]-x),abs(x-s[sm]))*2+max(abs(t[tl]-x),abs(x-s[sm])),ts = min(abs(s[sl]-x),abs(x-t[tm]))*2+max(abs(s[sl]-x),abs(x-t[tm]));
    cout << min({l,m,st,ts}) << endl;
  }


  return 0;
}