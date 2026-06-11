#include <iostream>
using namespace std;

int main() {
  int N, X_Y;
  cin >> N;
  
  int V[N], C[N];
  for(int i=0; i<N; i++) {
    cin >> V[i];
  }
  
  for(int i=0; i<N; i++) {
    cin >> C[i];
  }
  
  X_Y = 0;
  for(int i=0; i<N; i++) {
    if(V[i] > C[i]) {
      X_Y = X_Y + (V[i] - C[i]);
    }
  }
  
  cout << X_Y << endl;
  return 0;
}