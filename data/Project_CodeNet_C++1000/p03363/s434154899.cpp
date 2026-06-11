#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using ll = long long;
std::map<ll,int> frec;

int main() {
  int n;
  std::cin >> n;
  ll sum = 0;
  frec[sum]++;
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    sum += val;
    frec[sum]++;
    result += frec[sum] - 1;
  }
  std::cout << result;
  return 0;
}
