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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  cout << a[n - 1] - a[0] << endl;
}