#include <iostream>
#include <vector>
#include <set>
#include <map>

std::map<int, int> mp;

int nxt(int number) {
  int p = 1;
  while(p <= number) 
    p *= 2;
  return p;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    mp[val]++;
  }
  int result = 0;
  while(0 < mp.size()) {
    std::map<int,int>::iterator  it = mp.end();
    it--;
    if(it->second == 0)
      mp.erase(it);
    else {
      int oth = nxt(it->first) - it->first;
      if(oth == it->first) {
        if(1 < it->second) {
          it->second -= 2;
          result++;
        } else
          mp.erase(it);
      } else {
        if(0 < mp[oth]) {
          it->second--;
          mp[oth]--;
          result++;
        } else
          mp.erase(it);
      }
    }
  }
  std::cout << result;
  return 0;
}
