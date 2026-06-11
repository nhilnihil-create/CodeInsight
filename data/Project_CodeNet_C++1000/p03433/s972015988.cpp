#include <iostream>

using namespace std;

int main(void) {
  int N, A;
  cin >> N;
  cin >> A;

  N = N % 500;
  if(N > A){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}