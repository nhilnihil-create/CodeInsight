#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> ABC(3);
  std::cin >> ABC.at(0) >> ABC.at(1) >> ABC.at(2);
  sort(ABC.begin(), ABC.end());
  std::cout << ABC.at(2) * 10 + ABC.at(0) + ABC.at(1) << std::endl;
}
