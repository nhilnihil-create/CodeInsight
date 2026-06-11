#include <iostream>

using namespace std;

int main(){
  int n;
  string s;
  std::cin >> n >> s;

  int red_count = 0;
  for(int idx = 0; idx < s.size(); idx++){
    if(s[idx] == 'R') red_count += 1;
  }

  if(red_count > n - red_count){
    std::cout << "Yes" << '\n';
  }else{
    std::cout << "No" << '\n';
  }
  return 0;
}
