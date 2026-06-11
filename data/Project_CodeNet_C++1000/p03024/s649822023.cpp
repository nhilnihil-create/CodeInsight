#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  string S;
  cin >> S;
  int k, t;
  k=S.size();
  t=0;
  for (int i=0; i<k; i++) {
    if (S[i]=='o') {
      t=t+1;
    }
  }
  if (t-k+7>=0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}