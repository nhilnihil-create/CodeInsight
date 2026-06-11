#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin >> a[i];
  }
  std::sort(a.begin(),a.end());

  std::cout << a.back()-a.front();
}