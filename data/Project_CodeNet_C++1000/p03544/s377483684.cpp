#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int64_t> L(N+1);
  L[0] = 2;
  L[1] = 1;
  
  for(int i = 2; i < N+1; i++){
    L[i] = L[i-1] + L[i-2];
  }
  
  cout << L[N];
}