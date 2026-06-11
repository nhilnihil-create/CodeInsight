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
  ll k;
  cin >> k;
  vector<ll> a(k);
  for(int i = 0;i < k;i++)cin >> a[i];
  ll minres = 0;
  ll maxres = 0;
  if(a[k - 1] != 2){
    cout << -1 << endl;
    return 0;
  }
  minres = 2;
  maxres = 3;
  for(int i = k - 1;i >= 0;i--){
    minres = (minres + a[i] - 1) / a[i] * a[i];
    maxres = (maxres + a[i] - 1) / a[i] * a[i];
  }
  maxres--;
  if(minres == maxres + 1)cout << -1 << endl;
  else cout << minres << " " << maxres << endl;
}