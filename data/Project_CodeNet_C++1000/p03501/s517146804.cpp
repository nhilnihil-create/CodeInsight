#include <iostream>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  cout << ((A * N) <= B ? (A * N) : B) << endl;
}
