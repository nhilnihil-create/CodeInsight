#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)
using P = pair<ll,ll>;

int main() {
  int n,m,sum = 0;
  ll ans = 0;
  cin >> n >> m;
  vector<P>a(n);
  rep(i,0,n) cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end());
  rep(i,0,n){
    if(a[i].second+sum > m){
      ans += (m-sum)*a[i].first;
      break;
    }
    else{
      sum += a[i].second;
      ans += a[i].first*a[i].second;
    }
  }
  cout << ans << endl;
}