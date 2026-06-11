#include <iostream>
using namespace std;

int main(void){
  int N;
  int sum = 0;
  
  cin >> N;

  int tmp = N;
  while(tmp > 10){
    sum += tmp % 10;
    tmp /= 10;
  }
  sum += tmp;
 
 
  if(N%sum == 0) cout << "Yes" << "\n";
  else  cout << "No" << "\n";

}
