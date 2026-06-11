#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int X;
  cin >> X;
  int ans = 1;

  for (int b = 2; b < X; b++) {
    int power = b*b;
    for (int p = 2;; p++) {
      if(power > X) break;
      ans = max(ans, power);
      power *= b;
    }
  }

  cout << ans << endl;
  return 0;
}