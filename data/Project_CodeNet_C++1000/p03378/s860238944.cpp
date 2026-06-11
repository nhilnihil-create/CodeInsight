#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> A(N,0);
  for (int i=0; i<N; i++) {
    int a;
    cin >> a;
    A[a] = 1;
  }
  int ans_1,ans_2=0;
  for (int i=X; i<N; i++) {
    ans_1 += A[i];
  }
  for (int i=X; i>0; i--) {
    ans_2 += A[i];
  }
  cout << min(ans_1,ans_2) << endl;
  return 0;

}