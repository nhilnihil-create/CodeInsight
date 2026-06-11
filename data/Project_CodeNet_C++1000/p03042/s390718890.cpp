#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int upper = N /100, lower = N % 100;
  
  if (upper > 0 && upper <= 12) {
    if (lower > 0 && lower <= 12) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if (lower > 0 && lower <= 12) {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    } 
    
  }
  
  
  
}