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
  ll res = 1000000;
  for(int i = 1;i < n;i++){
    ll now = 0;
    string a = to_string(i);
    string b = to_string(n - i);
    for(int j = 0;j < (int)a.size();j++)now += a[j] - '0';
    for(int j = 0;j < (int)b.size();j++)now += b[j] - '0';
    res = min(res,now);
  }
  cout << res << endl;
}