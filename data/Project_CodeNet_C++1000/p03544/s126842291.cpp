#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int Y = 0;
  int64_t A = 2;
  int64_t B = 1;
  int64_t C = A + B;
  if (N == 1){
    cout << 1 << endl;
     Y = 1;
  }
  for (int i = 1; i < N; i++){
    int64_t A1 = A;
    int64_t B1 = B;
    int64_t C1 = A + B;
    A = B1;
    B = C1;
    C = A1 + B1;
  }
  if (Y == 0){
    cout << C << endl;
  }
  
}