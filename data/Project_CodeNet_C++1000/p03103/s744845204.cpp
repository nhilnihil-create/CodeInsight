#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> drink(n);
  REP(i,n){
    int a, b;
    cin >> a >> b;
    drink[i].first = a;
    drink[i].second = b;
  }

  sort(ALL(drink));

  ll ans = 0;

  REP(i,n){
    if( m >= drink[i].second){
      ans += (ll)drink[i].first * drink[i].second;
      m -= drink[i].second;
      if(m == 0) break;
    }
    else{
      ans += (ll)drink[i].first * m;
      break;
    }

  }

  cout << ans << endl;
  return 0;
}
