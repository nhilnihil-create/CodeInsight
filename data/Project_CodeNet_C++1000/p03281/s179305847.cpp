#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> jug(n);

  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i % j == 0 && i % 2 == 1) {
        jug.at(i-1)++;
      }  
    }
    if (jug.at(i-1) == 8) {
      count++;
    }
  } 
  cout << count << endl;
}