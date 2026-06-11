#include <iostream>

int main(void){
  int n, k, dsp = 1, i;
  std::cin >> n >> k;
  for(i = 0; i < n; i++){
    if(dsp < k) dsp *= 2;
    else dsp += k;
  }
  std::cout << dsp << std::endl;
  return 0;
}