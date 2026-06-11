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
  ll n,z,w;
  cin >> n >> z >> w;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  if(n != 1)cout << max(abs(a[n - 1] - w),abs(a[n - 1] - a[n - 2])) << endl;
  else cout << abs(a[0] - w) << endl;
}