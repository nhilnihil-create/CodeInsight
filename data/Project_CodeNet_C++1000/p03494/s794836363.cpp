#include <iostream>

int main(){
  int n;
  std::cin >> n;
  const int N = n;
  int a[N];
  int min = 0;
  for (int i = 0; i < N; i++){
    int count = 0;
    std::cin >> a[i];
    while (1){
      if (a[i] % 2 == 0){
        a[i] /= 2;
        count++;
      }else{
        if (min >= count | i == 0){
          min = count;
        }
        // std::cout << count << std::endl;
        break;
      }
    }
  }
  std::cout << min << std::endl;
  return 0;
}