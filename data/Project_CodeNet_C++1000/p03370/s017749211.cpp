#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,x,m[110];
  cin >> n >> x;
 
  int sum = 0;
  int mi = 1100;
  for(int i = 0; i < n; i++) {
    cin >> m[i];
    sum += m[i];
    mi = min(mi, m[i]);
  }
  
  int res = x - sum;
  cout << n + res/mi << endl; 
}