#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N;
 cin >> N;
 int i = 0;
 string y; 
 bool hasYellow = false;
  
  while (i < N) {
  	cin >> y;
    if (y == "Y") {
      hasYellow = true;
    }
    i++;
  }
  if (hasYellow) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
 
}
