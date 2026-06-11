#include <iostream>
#include <vector>

int main(void){
  int n, dia, max=0, i;
  std::cin >> n;
  std::vector<int> d(101);
  for(i=0; i<n; i++){
    std::cin >> dia;
    d.at(dia) = 1;
    if(dia > max) max = dia;
  }
  for(i=0; i<max; i++) d.at(i+1) += d.at(i);
  std::cout << d.at(max);
  return 0;
}