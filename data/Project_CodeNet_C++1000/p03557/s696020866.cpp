#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N), B(N), C(N);
  
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  for(int i=0; i<N; i++) cin >> C[i];
  
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());

  long long ans = 0;
  
  for(int i=0; i<N; i++){
    auto index = lower_bound(A.begin(), A.end(), B[i]);
    long long indexA = index - A.begin();
    auto index2 = upper_bound(C.begin(), C.end(), B[i]);
    long long indexC = C.end()-index2;
  	ans += indexA*indexC;
  }
  
  cout << ans << endl;

  return 0;
}