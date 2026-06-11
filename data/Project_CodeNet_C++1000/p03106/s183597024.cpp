#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int k,a,b,x[100];
  cin >> a >> b >> k;
  
  int j = 0;
  for(int i = 1; i <= a; i++) {
    if(a % i == 0 & b % i == 0) {
      x[j] = i;
      j++;
    }
  }
  cout << x[j-k] << endl;
}