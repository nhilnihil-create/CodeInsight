#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  map<ll, ll> mp;
  for(int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  int cnt = 0;
  for(auto p : mp) {
    if(p.first < p.second) {
      cnt += p.second - p.first;
    } else if(p.first > p.second) {
      cnt += p.second;
    }
  }
  cout << cnt << endl;
  return 0;
}