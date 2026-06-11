#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,m,q;
  cin >> n >> m >> q;
  vector<vector<ll>> train(n,vector<ll>(n));
  for(int i = 0;i < n;i++)for(int j = 0;j < n;j++)train[i][j] = 0;
  ll lmin = 0;
  ll rmax = 0;
  lmin = 100000;
  for(int i = 0;i < m;i++){
    ll l,r;
    cin >> l >> r;
    l--,r--;
    lmin = min(lmin,l);
    rmax = max(rmax,r);
    train[l][r]++;
  }
  for(int i = 0;i < q;i++){
    ll l,r;
    cin >> l >> r;
    l--,r--;
    if(l <= lmin && r >= rmax){
      cout << m << endl;
      continue;
    }
    ll res = 0;
    for(int j = l;j <= r;j++){
      for(int k = l;k <= r;k++){
        res += train[j][k];
      }
    }
    cout << res << endl;
  }
}