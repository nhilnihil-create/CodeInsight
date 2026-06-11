#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int L[N];
  for (int i = 0; i < N; i++) cin >> L[i];
  
  sort(L, L+N);
  
  int subsum = 0;
  for (int i = 0; i < N-1; i++) {
    subsum += L[i];
  }
  
  if (subsum > L[N-1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}