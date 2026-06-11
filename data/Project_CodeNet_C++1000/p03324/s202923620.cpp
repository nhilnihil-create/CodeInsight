#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int D, N, ans;
  cin >> D >> N;
  if (D==0) {
    if (N==100) {
      ans=101;
    }
    else {
      ans=N;
    }
  }
  else {
    if (D==1) {
      if (N==100) {
        ans=10100;
      }
      else {
        ans=100*N;
      }
    }
    else {
      if (N==100) {
        ans=1010000;
      }
      else {
        ans=10000*N;
      }
    }
  }
  cout << ans << endl;
}