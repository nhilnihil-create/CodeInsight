#include <bits/stdc++.h>
using namespace std;
int main(){
  int S;
  cin >> S;
  int A = S / 100, B = S % 100;
  if (0 < A && A < 13 && 0 < B && B < 13) {cout << "AMBIGUOUS" << endl;}
  else if (0 < B && B < 13) {cout << "YYMM" << endl;}
  else if (0 < A && A < 13) {cout << "MMYY" << endl;}
  else {cout << "NA" << endl;}
}