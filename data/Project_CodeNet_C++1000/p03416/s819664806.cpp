#include <iostream>

int main(void){
  int a, b, tmp, count = 0;
  std::cin >> a >> b;
  while(a <= b){
    tmp = a;
    if(tmp/10000%10 == tmp%10)
      if(tmp/1000%10 == tmp/10%10)
        count++;
    a++;
  }
  std::cout << count << std::endl;
  return 0;
}