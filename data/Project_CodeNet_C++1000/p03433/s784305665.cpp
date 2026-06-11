#include <iostream>
using namespace std;

int main(){

  //initialization
  int N, A;
  int surplus;
  //input
  cin >> N;
  cin >> A;
  
  //solver
  surplus = N % 500;
  if(A >= surplus) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
