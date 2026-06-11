#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll h, w, d;
  cin >> h >> w >> d;
  
  map<ll, P> m;
  for (ll i = 0; i < h; i++){
    for (ll j = 0; j < w; j++){
      ll a;
      cin >> a;
      
      m[a] = P(i, j);
    }
  }


  vector<vector<ll>> accsum(d, vector<ll>(h*w/d + 1, 0));

  for (ll i = 0; i < d; i++){
    for (ll j = 1; j < h*w/d + 1; j++){
      P p = m[i + d*(j-1)];
      P q = m[i + d*j];
      accsum[i][j] = accsum[i][j-1] + abs(p.first - q.first) + abs(p.second - q.second);
    }
  }
  

  ll q;
  cin >> q;
  for (ll i = 0; i < q; i++){
    ll l, r;
    cin >> l >> r;
    
    cout << accsum[l % d][r / d] - accsum[l%d][l/d] << endl;
  }

  return 0;
}
