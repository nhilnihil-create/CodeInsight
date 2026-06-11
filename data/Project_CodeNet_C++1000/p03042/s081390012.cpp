#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  int a = s / 100;
  int b = s % 100;
  if(a >= 1 && a <= 12) {
    if(b >= 1 && b <= 12) {
      cout << "AMBIGUOUS" << endl;
    }
    else {
      cout << "MMYY" << endl;
    }
  }
  else {
    if(b >= 1 && b <= 12) {
      cout << "YYMM" << endl;
    }
    else {
      cout << "NA" << endl;
    }
  }
}