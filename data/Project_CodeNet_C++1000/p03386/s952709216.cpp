#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
   for (int i = 0; i < B - A + 1; i++) {
     int x = A + i;
     if (x <= A + K -1 || x >= B - K + 1)
       cout << x << endl;
   }
}