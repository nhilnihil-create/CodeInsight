#include <iostream>
using namespace std;

int main() {
	int A;
  int B;
  cin >> A;
  cin >> B;
  if(A+B>A+A-1 && A+B>B+B-1){
    cout << A+B;
  }else if(A+A-1>B+B-1){
    cout << A+A-1;
  }else{
    cout << B+B-1;
  }
	return 0;
}
