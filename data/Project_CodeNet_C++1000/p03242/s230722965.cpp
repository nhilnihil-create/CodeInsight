#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  if (n.at(0) == '1') {
    n.at(0) = '9';
  }
  else if (n.at(0) == '9') {
    n.at(0) = '1';
  }
  if (n.at(1) == '1') {
    n.at(1) = '9';
  }
  else if (n.at(1) == '9') {
    n.at(1) = '1';
  }
  if (n.at(2) == '1') {
    n.at(2) = '9';
  }
  else if (n.at(2) == '9') {
    n.at(2) = '1';
  }
  cout << n << endl;
}