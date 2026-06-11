#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  
  vector<bool> A(N, false);
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    A[x] = true;
  }
  
  int left = 0, right = 0;
  
  for (int i = X-1; i > 0; i--) {
    if (A[i]) left++;
  }
  
  for (int i = X+1; i < N; i++) {
    if (A[i]) right++;
  }
  
  cout << min(left, right) << endl;
 
  

}