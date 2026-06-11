#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int s;
  cin >> s;
  
  int x = s / 100;
  int y = s % 100;
  
  if(x <= 12 && y <= 12 && x != 0 && y != 0) {
    cout << "AMBIGUOUS" << endl;
  } else if (y <= 12 && y != 0) {
    cout << "YYMM" << endl;
  } else if (x <= 12 && x != 0) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
  
}
