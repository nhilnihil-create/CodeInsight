#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A;
  int B;
  int C;
  cin >> A;
  cin >> B;
  cin >> C;
  int seged=0;
  if(A>B && A>C){
    seged+=A*10;
   seged+=B+C;
    
  }else if(B>C){
    seged+=B*10;
    seged+=A+C;
  }else{
    seged+=C*10;
    seged+=A+B;
  }
  cout << seged;
  	return 0;
    
}
