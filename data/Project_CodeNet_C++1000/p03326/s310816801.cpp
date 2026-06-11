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
  ll n,m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> z(n);
  for(int i = 0;i < n;i++)cin >> x[i] >> y[i] >> z[i];
  ll res = 0;
  for(int i = 0; i < (1<<3); i++){//2のa乗回繰り返す(0 ~ 2^a- 1)
    vector<ll> now(n);
    for(int j = 0;j < n;j++)now[j] = 0;
    for(int j = 0;j < n;j++){
      if(i & (1<<0))now[j] += x[j];
      else now[j] += x[j] * -1;
      if(i & (1<<1))now[j] += y[j];
      else now[j] += y[j] * -1;
      if(i & (1<<2))now[j] += z[j];
      else now[j] += z[j] * -1;
    }
    /*if(i == 7){
      for(auto item:now)cout << item << " ";
      cout << endl;
    }*/
    sort(now.rbegin(),now.rend());
    ll wa = 0;
    for(int j = 0;j < m;j++){
      wa += now[j];
      //cout << now[j] << " ";
    }
    //cout << endl;
    res = max(res,wa);
  }
  cout << res << endl;
}