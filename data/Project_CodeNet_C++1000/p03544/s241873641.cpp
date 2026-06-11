#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  long L,L1 = 1,L2 = 2;
  cin >> n;
  
  L = L1 + L2;
  for(int i = 2; i < n; i++) {
    L2 = L1;
    L1 = L;
    L = L1 + L2;
  }
  if(n == 1) L = 1;
  cout << L << endl;
}