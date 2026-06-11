#include <iostream>
using namespace std;


int main(void){
  int N, A, B;
  cin >> N >> A >> B;
  
  if((B-A)%2 == 1) cout << "Borys" <<"\n";
  else cout << "Alice" <<"\n";

}//main
