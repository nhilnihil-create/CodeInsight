#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  // input
  int N;
  map<long long, long long> nums;
  cin >> N;
  vector<long long> S(N+1, 0);
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    S.at(i) = tmp + S.at(i-1);
  }

  // solve
  for (int i = 0; i <= N; i++) {
    nums[S.at(i)]++;
  }

  long long ans {0};
  for (auto it : nums) {
    long long num = it.second;
    ans += num * (num - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
