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
  vector<int> a(n);
  map<int, int> mp1, mp2;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i % 2 == 0) {
      mp1[a[i]]++;
    } else {
      mp2[a[i]]++;
    }
  }

  int m1 = 0;
  int idx1 = 0;
  for(auto p : mp1) {
    if(m1 < p.second) {
      m1 = p.second;
      idx1 = p.first;
    }
  }
  int m2 = 0;
  int idx2 = 0;
  for(auto p : mp2) {
    if(m2 < p.second) {
      m2 = p.second;
      idx2 = p.first;
    }
  }
  int m3 = 0;
  int idx3 = 0;
  for(auto p : mp1) {
    if(p.first == idx1) {
      continue;
    }
    if(m3 < p.second) {
      m3 = p.second;
      idx3 = p.first;
    }
  }
  int m4 = 0;
  int idx4 = 0;
  for(auto p : mp2) {
    if(p.first == idx2) {
      continue;
    }
    if(m4 < p.second) {
      m4 = p.second;
      idx4 = p.first;
    }
  }
  if(idx1 != idx2) {
    cout << n - mp1[idx1] - mp2[idx2] << endl;
  } else {
    cout << min(n - mp1[idx3] - mp2[idx2], n - mp1[idx1] - mp2[idx4]) << endl;
  }

  return 0;
}