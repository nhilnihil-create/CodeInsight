#include <algorithm>
#include <iostream>
#include <map>
#include <set>

template <typename Map>
void print_map(const Map &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.begin(), c.end(),
                [](auto &x) { std::cout << x.first << "->" << x.second << ", "; });
  std::cout << std::endl;
}

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

void shrink(
    std::multimap<std::string, int> &lut,
    std::set<std::string> &lut_uniq,
    size_t k)
{
  bool deletes = false;
  std::string last_str = "";
  for(auto it=lut.begin(); it!=lut.end(); ) {
    if(deletes && it->first != last_str) {
      it = lut.erase(it);
    } else {
      lut_uniq.insert(it->first);
      if(lut_uniq.size() == k) {
        deletes = true;
        last_str = it->first;
      }
      it++;
    }
  }
}

int main()
{
  std::string s;
  size_t K;
  std::cin >> s >> K;

  int len = (int)s.size();

  // substr vs pos
  std::multimap<std::string, int> lut[K];
  std::set<std::string> lut_uniq[K];

  for(int i=0; i<len; i++) {
    lut[0].insert(std::make_pair(s.substr(i, 1), i));
  }
  // print_map(lut[0], "lut[0]");
  shrink(lut[0], lut_uniq[0], K);
  // print_container(lut_uniq[0], "lut_uniq[0]");

  for(int i=1; i<(int)K; i++) {
    for(auto it: lut[i-1]) {
      if(it.second <= len-(i+1)) {
        lut[i].insert(std::make_pair(s.substr(it.second, i+1), it.second));
      }
    }
    // print_map(lut[i], "lut[" + std::to_string(i) + "]");
    shrink(lut[i], lut_uniq[i], K);
    // print_container(lut_uniq[i], "lut_uniq[" + std::to_string(i) + "]");
  }

  std::set<std::string> substr;
  for(int i=0; i<(int)K; i++) {
    for(auto a: lut[i]) {
      substr.insert(a.first);
    }
  }
  auto it = substr.begin();
  // print_container(substr, "substr");

  std::cout << *(std::next(it, K-1)) << std::endl;
  return 0;
}
