#include <iostream>

using namespace std;

int main(){
  int Dishes[5], min_min=10, min_i=0, s=0;
  for (int i = 0; i < 5; i++){
    cin >> Dishes[i];
    if (Dishes[i]%10 != 0 && Dishes[i]%10 < min_min){
      min_min = Dishes[i]%10;
      min_i = i;
    }
  }

  for (int i = 0; i < 5; i++){
    if (i!=min_i && Dishes[i]%10 != 0){
      Dishes[i] = (Dishes[i] / 10 + 1) * 10;
    }
    s += (Dishes[i]);
  }
  printf("%d\n", s);
  
}
