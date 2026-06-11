#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }
  rep(i, n) {
    cin >> c[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  vector<int>tmp(n);
  vector<long long>cum(n);
  rep(i, n) {
    int x = b[i];
    int ok = n;
    int ng = -1;
    while(abs(ok-ng) > 1) {
      int mid = (ok + ng) / 2;
      //cout << a[mid];
      if(a[mid] >= x) {
        ok = mid;
      }
      else {
        //cout << x << ":" << ng << endl;
        ng = mid;
      }
    }
    if(i == 0) {cum[i] = ok;}
    else { cum[i] += cum[i-1] + ok; }
  }
  //rep(i, n) {
  //  cout << cum[i] << " ";
  //}
  cout << endl;
  long long sum = 0;
  rep(i, n) {
    int x = c[i];
    int ok = n;
    int ng = -1;
    while(abs(ok-ng) > 1) {
      int mid = (ok + ng) / 2;
      if(b[mid] >= x) {
        ok = mid;
      }
      else {
        ng = mid;
      }
    }
    if(ok != 0) {
      sum += cum[ok-1];
    }
  }
  //rep(i, n) {
  //  cout << a_sort[i] << " ";
  //}
  //cout << endl;
  //rep(i, n) {
  //  cout << b_sort[i] << " ";
  //}
  //cout << endl;
  cout << sum << endl;
}
