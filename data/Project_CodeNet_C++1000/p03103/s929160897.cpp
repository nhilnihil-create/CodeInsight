#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<pair<ll,ll>> p(n);
  rep(i,n){
    ll a,b; cin >> a >> b;
    p[i] = make_pair(a,b);
  }

  sort(p.begin(),p.end());
  /*cout << "sorted" << endl;
  for(auto x : p)
    cout << x.first << " " << x.second << endl;
  cout << "end" << endl;
  */
  ll ans = 0;
  ll num = 0;
  for(auto x : p){
    ll a = x.first;
    ll b = x.second;

    ans = num+b>=m ? ans+a*(m-num):ans+a*b;
    num += b;
    //cout << "a: " << a << " b: " << b << " ans: " << ans << " num: " << num << endl;
    if(num>=m) break;
  }

  cout << ans << endl;
  
  return 0;
}
