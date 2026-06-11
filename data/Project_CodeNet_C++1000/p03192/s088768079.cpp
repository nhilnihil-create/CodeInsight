#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string N;
  int ans=0;
  cin >> N;
  for (int i=0; i<4; i++) {
    if (N.at(i)=='2') {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
