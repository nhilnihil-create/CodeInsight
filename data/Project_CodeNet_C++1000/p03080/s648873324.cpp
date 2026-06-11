#include <iostream>
int n, r, b;
std::string s;
int main(){
  std::cin >> n >> s;
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') r++;
    else b++;
  }
  if(r > b) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}