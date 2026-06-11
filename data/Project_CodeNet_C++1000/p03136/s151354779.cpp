#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  int L[N];
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  
  sort(L, L+N);
  
  int sum = 0;
  for (int i = 0; i < N-1; i++) {
    sum += L[i];
  }
  
  if(sum<=L[N-1]) cout << "No" << endl;
  else cout << "Yes" << endl;
  
  
  return 0;
}