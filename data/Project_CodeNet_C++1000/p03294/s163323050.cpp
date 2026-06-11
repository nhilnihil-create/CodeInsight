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
  ll res = 0;
  for(int i = 0;i < n;i++){
    ll num = 0;
    cin >> num;
    res += num;
  }
  res -= n;
  cout << res << endl;
}