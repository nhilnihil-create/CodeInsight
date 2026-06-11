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
  map<ll,ll> a;
  for(int i = 0;i < n;i++){
    ll diff = 0;
    cin >> diff;
    a[diff]++;
  }
  ll m = 0;
  cin >> m;
  map<ll,ll> b;
  for(int i = 0;i < m;i++){
    ll diff = 0;
    cin >> diff;
    b[diff]++;
  }
  bool can = true;
  for(auto i:b){
    if(i.second > a[i.first])can = false;
  }
  if(can)cout << "YES" << endl;
  else cout << "NO" << endl;
}