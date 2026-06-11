#include <iostream>
#define SIZE 200

int main(void){
  int n, a[SIZE], count = -1, i;
  bool frag = true;
  std::cin >> n;
  for(i = 0; i < n; i++) std::cin >> a[i];
  while(frag){
    for(i = 0; i < n && frag; i++){
      if(a[i] % 2 != 0) frag = false;
      a[i] /= 2;
    }
    count++;
  }
  std::cout << count << std::endl;
  return 0;
}