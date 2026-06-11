#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int x = 0;
   for (int i = 1; i < N+1; i++) {
     int y = 0;
     y = i/10000 + (i/1000 - i/10000 * 10) + 
       (i/100 - i/1000 * 10) + (i/10 - i/100 *10) +
       (i - i/10 * 10);
       if (y >= A && y <= B)
         x += i;
   }
  cout << x << endl;
}