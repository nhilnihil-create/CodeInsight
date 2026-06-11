// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, d; cin >> d >> n;
  int s = 1;
  while (d--) s *= 100;
  if (n==100) n = 101;
  cout << s * n << endl;
  return 0;
}
