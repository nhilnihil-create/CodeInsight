#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int count = 0;
  
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 15; j++) {
      if (4 * i + 7 * j == N) {
        count++;
        break;
      }
    }
  }
  
  if (count == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  
}