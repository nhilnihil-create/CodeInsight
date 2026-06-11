#include <bits/stdc++.h>
using namespace std;

int main() { 
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++){
    cin >> v.at(i);
  }
  int e = 50;

  for (int i = 0; i < N; i++){
    int d = 0;
    for (int j = 0; j < 50; j++) {
      if (v.at(i) % 2 == 0) {
        v.at(i) /= 2;
        d += 1;

      } else {
        if (d < e) {
          e = d;
          break;
        }
      }
    }
  }
  cout << e << endl;
}
