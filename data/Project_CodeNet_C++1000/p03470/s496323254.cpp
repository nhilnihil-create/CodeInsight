#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;

  std::vector<int> ds;
  for (int i=1; i<=N; i++) {
    int d;
    std::cin >> d;
    ds.push_back(d);
  }
  std::sort(ds.begin(), ds.end(), std::greater<int>());

  int prev = 101;
  int count = 0;
  for (auto d : ds) {
    if (d < prev) {
      count++;
      prev = d;
    }
  }

  std::cout << count << std::endl;
}