#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<vector<ll>> open(n,vector<ll>(10));
  for(int i = 0;i < n;i++){
    for(int j = 0;j < 10;j++){
      cin >> open[i][j];
    }
  }
  vector<vector<ll>> benefit(n,vector<ll>(11));
  for(int i = 0;i < n;i++){
    for(int j = 0;j < 11;j++){
      cin >> benefit[i][j];
    }
  }
  ll res = 0;
  res = INT_MIN;
  for(int i = 0;i < (1<<10);i++){
    ll now = 0;
    vector<ll> count(n);
    for(int j = 0;j < n;j++)count[j] = 0;
    bool any = false;
    for(int j = 0;j < 10;j++){
      if(i & (1<<j)){
        any = true;
        for(int k = 0;k < n;k++){
          if(open[k][j] == 1)count[k]++;
        }
      }
    }
    for(int j = 0;j < n;j++)now += benefit[j][count[j]];
    if(any)res = max(res,now);
    //cout << now << " " << i << endl;
  }
  cout << res << endl;
  return 0;
}