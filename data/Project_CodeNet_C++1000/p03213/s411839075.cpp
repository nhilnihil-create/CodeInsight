#include <iostream>
#include <vector>

using namespace std;

int Count(const vector<int>& divs, int n) {
  int res = 0;
  for (int cnt : divs) {
    if (cnt >= n-1) ++ res;
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  
  vector<int> divs(N+1);
  for (int i = 2; i <= N; ++i) {
    int n = i;
    for (int j = 2; j <= i; ++j) {
      while (n % j == 0) {
        ++divs[j];
        n /= j;
      }
    }
  }

  int res = 0;
  res += Count(divs, 75);
  res += Count(divs, 25) * (Count(divs, 3) - 1);
  res += Count(divs, 15) * (Count(divs, 5) - 1);
  res += Count(divs, 5) * (Count(divs, 5) - 1) * (Count(divs, 3) - 2) / 2;
  
  cout << res << endl;
  
  return 0;
}
