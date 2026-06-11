#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int Getinfo(int idx) {
  cout << idx << endl;
  string s;
  cin >> s;
  if (s == "Vacant")
    exit(0);
  else if (s == "Male")
    return 1;
  else
    return 0;
}

int main() {
  int n;
  cin >> n;
  auto buf = vector<int>(n, 0);
  buf[0] = Getinfo(0);
  buf[n - 1] = Getinfo(n - 1);
  int left = 0, right = n - 1;
  // 解の存在範囲は[left, right]
  while (true) {
    int mid = (left + right) / 2;
    buf[mid] = Getinfo(mid);
    if (abs(mid - left) % 2 != abs(buf[left] - buf[mid]) % 2) {
      // 奇数の幅で、両端が異性
      // または偶数の幅で、両端が同性
      // [left,mid]について
      right = mid;
    } else {
      left = mid;
    }
  }
  return 0;
}
