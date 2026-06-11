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
  ll n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<ll> l(n);
  for(int i = 0;i < n;i++)cin >> l[i];
  ll res = 0;
  res = pow(10,18);
  vector<ll> p(n);
  for(int i = 0;i < n;i++)p[i] = 0;
  for(int i = 0;i < pow(4,n);i++){
    ll change = -1;
    for(int j = 0;j < n;j++){
      if(p[j] <= 2){
        p[j]++;
        change = j;
        break;
      }
    }
    if(change == -1)break;
    //cout << "A" << endl;
    for(int j = 0;j < change;j++)p[j] = 0;
    ll ae = 0;
    ll be = 0;
    ll ce = 0;
    ll now = 0;
    for(int j = 0;j < n;j++){
      if(p[j] == 1)ae += l[j],now += 10;
      if(p[j] == 2)be += l[j],now += 10;
      if(p[j] == 3)ce += l[j],now += 10;
    }
    if(ae*be*ce == 0)continue;
    now += abs(a - ae) + abs(b - be) + abs(c - ce);
    now -= 30;
    res = min(res,now);
  }
  cout << res << endl;
}