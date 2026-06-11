#include <iostream>
#include <vector>
#include <map>

int main()
{
  int N;
  std::cin >> N;
  std::map<std::string, std::map<int, int, std::greater<int>>> city_point_restrant;

  for(int i=0; i<N; i++) {
    std::string s;
    int p;
    std::cin >> s >> p;
    city_point_restrant[s].insert(std::make_pair(p, i+1));
  }

  for(auto &cpr: city_point_restrant) {
    for(auto &pr: cpr.second) {
      std::cout << pr.second << std::endl;
    }
  }
  return 0;
}
