#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  int A[5];
  for (auto &a: A) {
    cin >> a;
  }

  sort(ALL(A),[](int a, int b){ return (a-1)%10 < (b-1)%10; });

  int ans = accumulate(begin(A)+1,end(A),A[0],[](int acc, int x){ return acc+((x+9)/10)*10;});
  cout << ans << endl;
  
  return 0;
}
