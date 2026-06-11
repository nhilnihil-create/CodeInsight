#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  std::cin >> n;

  string abc[3];
  std::cin >> abc[0] >> abc[1] >> abc[2];

  int ans = 0;
  for(int idx = 0; idx < n; idx++){
    if(abc[0].at(idx) == abc[1].at(idx) && abc[1].at(idx) == abc[2].at(idx)){
      continue;
    }
    if(abc[0].at(idx) == abc[1].at(idx) || abc[1].at(idx) == abc[2].at(idx) || abc[0].at(idx) == abc[2].at(idx)){
      ans += 1;
      continue;
    }
    if(abc[0].at(idx) != abc[1].at(idx) && abc[1].at(idx) != abc[2].at(idx) && abc[0].at(idx) != abc[2].at(idx)){
      ans += 2;
      continue;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
