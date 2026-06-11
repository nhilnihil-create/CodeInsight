#include <iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int count = 0;
  for(int i = 0; i < 3; i++){
    if (S.at(i) == 'o'){
      count += 100;
    }
  }
  cout << 700 + count << endl;
}