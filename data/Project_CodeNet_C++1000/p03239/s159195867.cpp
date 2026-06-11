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
  ll n,t;
  cin >> n >> t;
  ll res = 0;
  res = pow(10,18);
  for(int i = 0;i < n;i++){
    ll c,time;
    cin >> c >> time;
    if(time <= t)res = min(c,res);
  }
  if(res != pow(10,18))cout << res << endl;
  else cout << "TLE" << endl;
}