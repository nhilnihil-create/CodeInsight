#include <bits/stdc++.h>

using namespace std;

const int N = 134567;

int n, a[N];

// comb(a, b  ) = (a!) / (b!     * (a-b)!  )
// comb(a, b+1) = (a!) / ((b+1)! * (a-b-1)!)
// comb(a, b) / comb(a, b+1) = (b+1) / (a-b) >= 1
// b+1 >= a-b
// b*2 >= a-1

// a=9,b=4
// a=10,b=5

int main() {

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);

  int cur_v = min(a[0], a[n - 1] - a[0]), res = a[0]; 
  for (int i = 1; i < n - 1; ++i) {
    int v = min(a[i], a[n - 1] - a[i]);
    if (v > cur_v) { cur_v = v; res = a[i]; }
  }
  cout << a[n - 1] << " " << res << endl;

  return 0;
}