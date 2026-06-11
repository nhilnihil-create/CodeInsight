#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for (auto &x: h) {
    cin >> x;
  }
  sort(begin(h),end(h));
  transform(begin(h)+K-1,end(h),begin(h),begin(h),
            [](int x, int y){return x - y;});
  cout << *min_element(begin(h),end(h)-K+1) << endl;
}
