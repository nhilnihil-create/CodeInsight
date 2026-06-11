#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int z;
  z = a;
  int count = 0;
  while (z <= b) {
    int zin = z;
    int k1 = zin / 10000;
    int zin1 = zin % 10000;
    int k2 = zin1 / 1000;
    int zin2 = zin1 % 1000;
    int k3 = zin2 / 100;
    int zin3 = zin2 % 100;
    int k4 = zin3 / 10;
    int zin4 = zin3 % 10;
    int k5 = zin4;
    if (k1 == k5) { 
      if (k2 == k4) {
        count++;
      }
    }
  z++;
  }
  cout << count << endl; 
}
