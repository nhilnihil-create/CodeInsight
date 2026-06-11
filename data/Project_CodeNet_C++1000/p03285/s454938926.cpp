#include <iostream>
using namespace std;
const int ARRAY = 30;

int main(void){
  int N;
  cin >> N;

  while( N > 0){
    if( N % 4 == 0 || N % 7 == 0) {
      cout << "Yes" << "\n";
      return 0;
    } else {
      N -= 7;
    }
  }
  
  cout << "No" << "\n";
}
