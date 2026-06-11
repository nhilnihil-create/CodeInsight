#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int S, A, B;
  cin >> S;
  B=S%100;
  A=(S-B)/100;
  if (1<=A && A<=12) {
    if (1<=B && B<=12) {
      cout << "AMBIGUOUS" << endl;
    }
    else {
      cout << "MMYY" << endl;
    }
  }
  else {
    if (1<=B && B<=12) {
      cout << "YYMM" << endl;
    }
    else {
      cout << "NA" << endl;
    }
  }
}