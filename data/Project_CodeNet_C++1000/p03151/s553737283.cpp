#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int i = 0;i < n;i++)cin >> b[i];
  ll res = 0;
  vector<int> add;
  ll tarinai = 0;
  for(int i = 0;i < n;i++){
    if(a[i] > b[i])add.push_back(a[i] - b[i]);
    else if(a[i] < b[i])res++,tarinai += b[i] - a[i];
  }
  sort(add.begin(),add.end());
  for(int i = add.size() - 1;i >= 0;i--){
    if(tarinai > 0)tarinai -= add[i],res++;
    else break;
  }
  if(tarinai > 0)res = -1;
  cout << res << endl;
  return 0;
}