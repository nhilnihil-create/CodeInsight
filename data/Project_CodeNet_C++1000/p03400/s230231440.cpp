#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D,X;
  cin >> N >> D >> X;
 
  int count = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    int day = 0;
    while (day < D) {
      count++;
      day += x;
    }
  }
  
  cout << X + count << endl;
  
}