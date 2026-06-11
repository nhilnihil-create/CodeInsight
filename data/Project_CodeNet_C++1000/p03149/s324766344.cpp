#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  vector<int> a(4);
  cin >> a.at(0) >> a.at(1) >> a.at(2) >> a.at(3);
  sort(a.begin(),a.end());
  if (a.at(0)==1 && a.at(1)==4 && a.at(2)==7 && a.at(3)==9) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}