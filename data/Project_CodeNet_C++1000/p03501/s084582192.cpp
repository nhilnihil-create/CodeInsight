#include <iostream>
using namespace std;
int main(void){
    // Your code here!
  int N, A, B;
  cin >> N >> A >> B;
  int x = A * N;
  if (x < B)
  cout << x << endl;
  if (x > B)
  cout << B << endl;
  if (x == B)
  cout << B << endl;
  
}
