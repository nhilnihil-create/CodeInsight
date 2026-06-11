#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int A[N];
  int cnt = N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 1; i <= D; i++){
    for(int j = 0; j < N; j++){
      if(i-1 > 0 && (i-1)%A[j]==0){
        cnt++;
      }
    }
  }
  cout << cnt+ X << endl;
}
