#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int count = 0;
  
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (i * 4 + j * 7 == N) {
        count++;
      }
    }
  }
  if (count > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
