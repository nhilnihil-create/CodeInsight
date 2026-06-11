#include <iostream>
using namespace std;

int main() {
  int n; string now, left, right;
  cin >> n;
  cout << 0 << endl; cin >> left;
  if(left == "Vacant") return 0;
  cout << n-1 << endl; cin >> right;
  if(right == "Vacant") return 0;

  int l = 0, r = n-1;
  while(true) {
    int mid = (l + r)>>1;
    int areaL = mid - l - 1;
    int areaR = r - mid - 1;
    cout << mid << endl; cin >> now;
    if(now == "Vacant") return 0;

    if((areaL&1 && left != now) || (areaL%2==0 && left == now)) {
      r = mid;
      right = now;
      continue;
    }
    if((areaR&1 && right != now) || (areaR%2==0 && right == now)) {
      l = mid;
      left = now;
      continue;
    }
  }
  return 0;
}