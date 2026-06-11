#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.at(5)=='0') {
    if (S.at(6)=='1'||S.at(6)=='2'||S.at(6)=='3'||S.at(6)=='4') {
      cout << "Heisei" << endl;
    }
    else {
      cout << "TBD" << endl;
    }
  }
  else {
    cout << "TBD" << endl;
  }
}