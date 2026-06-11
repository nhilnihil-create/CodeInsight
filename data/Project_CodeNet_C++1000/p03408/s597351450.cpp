#include <iostream>
#include <string>
#include <vector>

int main(void){
  int n, m, frag, max = 0, i, j;
  std::string str;
  std::cin >> n;
  std::vector<std::string> s(n);
  std::vector<int> c(n);
  
  for(i=0; i<n; i++){
    std::cin >> str;
    for(j=0, frag=0; j<i; j++){
      if(s.at(j) == str){
        c.at(j)++;
        frag = 1;
        break;
      }
    }
    if(frag == 1) continue;
    s.at(i) = str;
    c.at(i)++;
  }
  
  std::cin >> m;
  for(i=0; i<m; i++){
    std::cin >> str;
    for(j=0; j<n; j++){
      if(s.at(j) == str && c.at(j) > 0){
        c.at(j)--;
        break;
      }
    }
  }
  
  for(i=0; i<n; i++) max = (c.at(i) > max) ? c.at(i) : max;
  std::cout << max << std::endl;
  return 0;
}