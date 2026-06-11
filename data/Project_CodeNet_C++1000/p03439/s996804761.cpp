#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int left = 0;
  int right = N - 1;
  cout << left << endl;
  string s0;
  cin >> s0;
  if (s0 == "Vacant") return 0;
  cout << right << endl;
  string s1;
  cin >> s1;
  if (s1 == "Vacant") return 0;

  string s = s0;
  int query = 20 - 1;
  while (query--) {
    int mid = left + (right - left) / 2;
    cout << mid << endl;
    cin >> s;

    if (s == "Vacant") {
      break;
    } else {
      if ((s == s0 && (mid - left) % 2 == 1) ||
          (s != s0 && (mid - left) % 2 == 0)) {
        right = mid;
        s1 = s;
      } else {
        left = mid;
        s0 = s;
      }
    }
  }
  return 0;
}