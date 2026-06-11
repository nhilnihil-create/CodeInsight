#include<bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin >> s;
  int a, b;
  a = s / 100;
  b = s % 100;
  if (a == 0 || a > 12) {
    if (b == 0 || b > 12) {
      cout << "NA" << endl;
    } else {
      cout << "YYMM" << endl;
    }
  } else {
    if (b == 0 || b > 12) {
      cout << "MMYY" << endl;
    } else {
      cout << "AMBIGUOUS" << endl;
    }
  }
}