// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * x+y>(t - t_1)の場合には不可
 * x+yと(t-t_1)の偶奇が一致していない場合は不可
 */
int main() {
  int n; cin >> n;
  vector<int> A(n), B(n);
  loop(i,0,n) cin >> A[i];
  loop(i,0,n) cin >> B[i];
  int max_ = 0;
  loop(k,0,n) {
    int sum = 0;
    loop(i,0,n) {
      if (i==k) sum += A[i] + B[i];
      else if (i < k) sum += A[i];
      else sum += B[i];
    }
    max_ = max(max_, sum);
  }
  cout << max_ << endl;
  return 0;
}
