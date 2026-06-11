#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int D, X;
  int A[N];
  cin >> D >> X;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  
  int count=0;
  for (int i=0; i<N; i++) {
    for (int j=0, k=0; j<D; j++) {
      if (j==k*A[i]) {
        count++;
        k++;
      }
    }
  }
  
  cout << count+X << endl;
  
  return 0;
}
