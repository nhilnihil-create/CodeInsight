// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  vector<int> A(n);
  loop(i,0,n) cin >> A[i];
  
  int max_ = 0;
  loop(i,0,n-1) {
    loop(j,i+1,n) {
      int d = abs(A[i]-A[j]);
      if (max_ < d) max_ = d;
    }
  }
  cout << max_ << endl;
  return 0;
}
