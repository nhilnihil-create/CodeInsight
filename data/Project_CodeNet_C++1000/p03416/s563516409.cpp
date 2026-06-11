#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  int total = 0;
  for(int i = A; i < B + 1; i++) {
    if(i % 10 == i / 10000 && i / 10 % 10 == i / 1000 % 10) {
      total += 1;
    }
    else {
      continue;
    }
  }
  cout << total << endl;
}