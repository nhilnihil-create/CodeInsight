#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string color;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> color;
    if (color == "Y") {
      sum++;
    }
  }
  if (sum == 0) {
    cout << "Three" << endl;
  }
  else {
    cout << "Four" << endl;
  }  
}
