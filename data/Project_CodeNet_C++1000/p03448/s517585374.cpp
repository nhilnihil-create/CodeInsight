#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int y500, y100, y50, total;
  int count_ways = 0;
  cin >> y500 >> y100 >> y50 >> total;
  for (int i = 0; i <= y500; i++) {
    for (int j = 0; j <= y100; j++) {
      for (int k = 0; k <= y50; k++) {
        if (500 * i + 100 * j + 50 * k == total) {
          count_ways++;
        }
      }
    }
  }
  cout << count_ways << endl;
}