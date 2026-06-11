// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n, m; cin >> n >> m;
  int t = m * 1900 + (n-m) * 100;
  int b = 1;
  loop(i,0,m) b *= 2;
  cout << t * b << endl;
  return 0;
}
