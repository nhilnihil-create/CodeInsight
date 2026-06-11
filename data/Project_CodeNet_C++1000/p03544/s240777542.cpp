#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  long L[87];
  cin >> n;
  
  L[0] = 2; L[1] = 1;
  for(int i = 2; i <= n; i++) {
    L[i] = L[i-1] + L[i-2];
  }
  cout << L[n] << endl;
}