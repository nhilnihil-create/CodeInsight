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
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  ll res = n;
  for(int i = 0;i < n;i++)cin >> a[i],x -= a[i];
  sort(a.begin(),a.end());
  res += x / a[0];
  cout << res << endl;
}