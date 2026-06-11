#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  switch(N){
    case 1:
      cout << "Hello World"<<endl;
      break;
    case 2:
      int A,B;
      cin >> A >> B;
      cout << A+B <<endl;
      break;
  }
}