#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> v(n);  
  
  REP(i,n){
    int a,b;
    cin >> a >> b;
    v[i].first = a;
    v[i].second = b;
  }
  sort(v.begin(),v.end());
  ll ans = 0;
  ll i = 0;
  while(m > 0){
    if(v[i].second <= m){ 
      ans += v[i].first * v[i].second;
      m -= v[i].second;
    }
    else{
      ans += v[i].first * m;
      m = 0;
    }
    i++;
  }
  
  cout << ans << endl;
  
}
