// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, d, x; cin >> n >> d >> x;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  loop(i,0,n) {
    loop(j,0,d+1) {
      if (j*A[i] + 1 > d) break;
      x++;
    }
  }
  cout << x << endl;
  return 0;
}
