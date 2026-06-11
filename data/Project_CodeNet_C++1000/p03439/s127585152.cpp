#include <iostream>

int ask(int x) {
  std::string res;
  std::cout << x << "\n";
  std::cin >> res;

  if (res[0] == '0') {
    return 0;
  } else if (res[0] == 'M') {
    return 1;
  } else {
    return -1;
  }
}

bool judge(int left, int right, int left_x, int right_x) {
  if (left_x == right_x) {
    return (right - left) % 2 == 1;
  } else {
    return (right - left) % 2 == 0;
  }
}

int main() {
  int N;
  std::cin >> N;

  std::string res;
  int left = 0, right = N - 1;
  int left_x, right_x;

  int x = ask(left);
  if (x == 0) {
    return 0;
  }
  left_x = x;

  x = ask(right);
  if (x == 0) {
    return 0;
  }
  right_x = x;

  while (right - left > 1) {
    int mid = (left + right) / 2;
    x = ask(mid);
    if (x == 0) {
      return 0;
    }
    if (judge(left, mid, left_x, x)) {
      right = mid;
      right_x = x;
    } else {
      left = mid;
      left_x = x;
    }
  }

  return 0;
}