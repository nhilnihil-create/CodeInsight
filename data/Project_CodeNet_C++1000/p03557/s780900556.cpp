#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  long A[N],B[N],C[N];
  for (int i =0; i<N; i++) cin >> A[i];
  for (int i =0; i<N; i++) cin >> B[i];
  for (int i =0; i<N; i++) cin >> C[i];
  
  sort(A,A+N); sort(B,B+N); sort(C,C+N);
  
  long count =0;
  for (int i =0; i<N; i++) {
    count += (lower_bound(A,A+N,B[i]) - A) * (N - (upper_bound(C,C+N,B[i]) - C));
  }  
  cout << count << endl; 
} 