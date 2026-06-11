#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  string S;
  std::cin >> S;
  int price=700;
  if (S.at(0)=='o') {
     price+=100 ;/* code */
  }
  if (S.at(1)=='o') {
     price +=100;/* code */
  }
  if (S.at(2)=='o') {
  price +=100 ;/* code */
  }
  std::cout << price << '\n';
  return 0;
}
