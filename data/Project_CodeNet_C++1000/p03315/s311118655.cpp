#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  int ans=0;
  cin >> S;
  for (int i=0; i<4; i++) {
    if (S.at(i)=='+') {
      ans=ans+1;
    }
    else {
      ans=ans-1;
    }
  }
  cout <<ans <<endl;
}
