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
  ll n = 0;
  cin >> n;
  vector<ll> t(n);
  for(int i = 0;i < n;i++)cin >> t[i];
  sort(t.begin(),t.end());
  if(t[0] == 0){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> num(2 * n);
  for(int i = 0;i < n;i++){
    num[i] = t[i];
    num[2 * n - i - 1] = 24 - t[i];
  }
  ll now = 0;
  now = 100;
  ll res = 0;
  ll mae = 0;
  //for(int i = 0;i < num.size();i++)cout << num[i] << " ";
  //cout << endl;
  for(int i = 0;i < 2 * n;i++){
    if(i % 2 == 0){
      now = min(now,num[i] - mae);
      mae = num[i];
    }
  }
  now = min(now,24 - num[2 * n - 2]);
  res = now;
  now = 100;
  mae = 0;
  for(int i = 0;i < 2 * n;i++){
    if(i % 2 == 1){
      now = min(now,num[i] - mae);
      mae = num[i];
    }
  }
  now = min(now,24 - num[2 * n - 1]);
  res = max(res,now);
  cout << res << endl;
}