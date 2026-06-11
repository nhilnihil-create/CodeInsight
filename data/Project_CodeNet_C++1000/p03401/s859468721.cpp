#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int A[N+2] = {0};
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  
  
  
  int sum = 0;
  for (int i = 0; i <= N; i++) {
    sum += abs(A[i+1] - A[i]); 
  } 
  
  for (int i = 1; i <= N; i++) {
    int ans = sum;
    
    ans -= abs(A[i] - A[i-1]);
    ans -= abs(A[i+1] - A[i]);
    ans += abs(A[i+1]-A[i-1]);
    cout << ans << endl;
    
    
  }
  


}