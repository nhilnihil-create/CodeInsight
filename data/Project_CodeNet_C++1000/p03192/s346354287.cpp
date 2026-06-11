#include<iostream>
#include<string>
using namespace std;

int main(){
  int v, ans = 0;
  std::cin >> v;
  string s = std::to_string(v);
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '2')ans++;
  }
  std::cout << ans << std::endl;
  return 0;}
