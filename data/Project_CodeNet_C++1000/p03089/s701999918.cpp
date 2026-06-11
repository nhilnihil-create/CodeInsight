#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N+1);
  for (int i = 0; i < N; i++) cin >> A[i+1];
  
                             
  
  vector<int> perm;
  
  int last = N;
  for (int i = 1; i <= N; i++) {
    for (int j = last; j >= 1; j--) {
      
      // A[j] = j となる j を大きい方から探して見つかったらその要素を捨てる
      if (A[j] == j) {
        perm.push_back(j);
        A.erase(A.begin() + j);
        break;
      }
      
      // もし最後までA[j] = j となる j が見つからなかったら不可能
      if (j == 1) {
        cout << -1 << endl;
        return 0;
      }      
    }
    last--;
  }
  
  for (int i = N-1; i >= 0; i--) {
    cout << perm[i] << endl;
  }
  
                                      
  
}