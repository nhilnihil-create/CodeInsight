#include <bits/stdc++.h>
using namespace std;

// RGB Boxes
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int count = 0;
  for (int i = 0; i <= N / R; i++) {
    for (int j = 0; j <= N / G; j++) {
      int Bcan = N - (i * R + j * G);
      if (Bcan >= 0 && Bcan % B == 0) {
        count++;
      }
    }
  }
  cout << count << endl;
}