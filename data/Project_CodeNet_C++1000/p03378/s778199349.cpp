#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int A[M];
  for(int i = 0; i < M; i++) cin >> A[i];
  int sum0 = 0;
  int sumM = 0;
  if(X+1 == M || X-1 == 0){
    cout << 0 << endl;
    return 0;
  }
  for(int i = 0; i < M; i++){
    if(A[i]<X) sum0++;
    else sumM++;
  }
  cout << min(sum0, sumM) << endl; 
}
