#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  std::cin >> N;
  
  int i = 0;
  bool flg = false;
  while (i < N){
    string st;
    std::cin >> st;
    if (st == "Y"){
      flg = true;
    }
    i++;
  }
  if (flg){
    std::cout << "Four" << std::endl;
  }
  else{
    std::cout << "Three" << std::endl;
  }
}
