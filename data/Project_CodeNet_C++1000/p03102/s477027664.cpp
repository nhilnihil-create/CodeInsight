#include<bits/stdc++.h>
using namespace std;
int main() {
  int Length, Width, C, sum = 0, res = 0;
  cin >> Length >> Width >> C;
  vector<int> B(Width);
  vector<vector<int>> A(Length,vector<int>(Width));
  for(int i = 0; i < Width; i++) cin >> B[i];
  for(int i = 0; i < Length; i++) {
    for(int j = 0; j < Width; j++) {
      cin >> A[i][j];
    }
  }
  for(int i = 0; i < Length; i++) {
    for(int j = 0; j < Width; j++) {
      sum += A[i][j] * B[j];
    }
    sum += C;
    if(sum > 0) res++;
    sum = 0;
  }
  cout << res << endl;
}
      
  
  