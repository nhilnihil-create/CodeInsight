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
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  map<ll,ll> mp;
  a[0] %= m;
  mp[a[0]]++;
  for(int i = 1;i < n;i++){
    a[i] += a[i - 1];
    a[i] %= m;
    mp[a[i]]++;
  }
  ll res = 0;
  for(auto i:mp){
    res += (i.second - 1) * i.second / 2;
  }
  res += mp[0];
  cout << res << endl;
}