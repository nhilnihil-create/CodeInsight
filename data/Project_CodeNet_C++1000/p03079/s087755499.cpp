#include <iostream>

using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A == B && B== C){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }

  return 0;
}
