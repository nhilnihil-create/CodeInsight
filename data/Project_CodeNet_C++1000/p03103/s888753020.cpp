#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> tp;
  ll x, y, z;
  rep(i, n) {
    cin >> x >> y;
    z = x * y;
    //cout << z << endl;
    tp.push_back(make_tuple(x, y, z));
  }
  ll ans = 0;
  sort(tp.begin(), tp.end());
  rep(i, n) {
    //cout << "OK" << endl;
    //cout << get<0>(tp[i]) << endl;
    if(get<1>(tp[i]) >= m) {
      //cout << 1 << endl;
      ans += m * get<0>(tp[i]);
      break;
    }
    else{
      //cout << 2 << endl;
      ans += get<2>(tp[i]);
      m -= get<1>(tp[i]);
    }
  }
  cout << ans << endl;
  
    
  return 0;
}