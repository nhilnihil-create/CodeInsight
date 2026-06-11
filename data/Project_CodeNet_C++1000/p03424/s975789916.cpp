#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int num;
  string color, cnt = "Three";
  cin >> num;
  
  for (int i=0; i<num; ++i) {
    cin >> color;
    if (color == "Y") {
      cnt = "Four";
      break;
    }
  }
  
  cout << cnt << endl;
}