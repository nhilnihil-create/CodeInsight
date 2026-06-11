#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int count = 0;
  
  for (int i = 0; i < 4; i++) {
    char e;
    cin >> e;
    
    if (e == '+') {
      count++;
    } else {
      count--;
    }
  }
  cout << count << endl;
}