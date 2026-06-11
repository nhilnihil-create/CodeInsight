#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,L[100];
  cin >> n;

  int ma = 0;
  for(int i = 0; i < n; i++) {
    cin >> L[i];
    ma = max(ma, L[i]);
  }
  int sum = 0;
  for(int i = 0; i < n; i++)
     sum += L[i];

  if(ma < sum-ma)
    cout << "Yes" << endl;
  else
    cout << "No" << endl; 
}