#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  long long A, B, K;
  std::cin >> A >> B >> K;
  for (int k = 0; k < K; ++k) {
    A /= 2;
    B += A;
    std::swap(A, B);
  }
  if (K % 2 == 1)
     std::swap(A, B);
  std::cout << A << ' ' << B << std::endl;
  return 0;
}
