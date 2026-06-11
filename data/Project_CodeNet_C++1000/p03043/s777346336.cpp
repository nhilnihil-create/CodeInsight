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

const long INF = 1e9 + 1;

int main() {
  double n,k;
  cin >> n >> k;

  double sum = 0;
  for(int i = 1; i <= n; i++) {
    int cnt = 0;
    int t = i;
    while(t < k) {
      t *= 2;
      cnt++;
    }
    sum += pow((double)1/2, cnt);
  }
  sum /= n;

  cout << fixed << setprecision(20) << sum << endl;
}
