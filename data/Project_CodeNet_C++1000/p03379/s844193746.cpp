#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  vector<int> nums(N);
  vector<int> sorted(N);
  for (int n = 0; n < N; ++n) {
    cin >> nums[n];
    sorted[n] = nums[n];
  }
  sort(sorted.begin(), sorted.end());
  int64_t mid1 = sorted[N/2-1];
  int64_t mid2 = sorted[N/2];
  
  for (int64_t n : nums) {
    if (n <= mid1) {
      cout << mid2 << endl;
    } else {
      cout << mid1 << endl;
    }
  }
  
  return 0;
}
