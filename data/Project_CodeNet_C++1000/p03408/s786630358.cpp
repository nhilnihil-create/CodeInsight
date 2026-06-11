#include <iostream>
#include <map>
#include <set>

int main()
{
  int N, M;
  std::map<std::string, int> s_plus, s_minus;
  std::set<std::string> keys;

  std::cin >> N;
  for(int i=0; i<N; i++) {
    std::string s;
    std::cin >> s;
    s_plus[s]++;
    keys.insert(s);
  }

  std::cin >> M;
  for(int i=0; i<M; i++) {
    std::string s;
    std::cin >> s;
    s_minus[s]++;
    keys.insert(s);
  }

  int max_plus = -M;
  for(auto &s: keys) {
    int tmp = s_plus[s] - s_minus[s];
    max_plus = std::max(max_plus, tmp);
  }

  if(max_plus < 0) {
    max_plus = 0;  // if minus, say no word.
  }

  std::cout << max_plus << std::endl;

  return 0;
}
