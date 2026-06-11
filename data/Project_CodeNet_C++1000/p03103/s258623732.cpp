#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  long n, m;
  pair<long, long> a[110000];
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;
  
  sort(a, a+n);

  long sum = 0;
  for(int i = 0; i < n; i++) {
    if(m >= a[i].second) {
      sum += a[i].first * a[i].second;
      m -= a[i].second;
      if(m == 0) break;
    }
    else {
      sum += a[i].first * m;
      break;
    }
  }
  cout << sum << endl;
}