#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <climits>

using namespace std;

int main() {
   int n;

   cin >> n;

   int r = n, cnt = 0;

   while (r >= 3)
       r -= 3, cnt++;

   cout << cnt;
}
