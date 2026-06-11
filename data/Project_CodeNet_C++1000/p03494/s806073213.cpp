#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int a, max = 1000;
  for (int i=0; i<N; i++) {
    int count = 0;
    cin >> a;
    while (a%2 == 0) {
      count++;
      a /= 2;
    }
    if (count < max) {
      max = count;
    }
  }
  
  cout << max << endl;
}