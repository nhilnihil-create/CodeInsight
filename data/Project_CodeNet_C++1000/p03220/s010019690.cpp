#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A; cin >> N >> T >> A;
  int H[N];
  double avetemp[N];
  double diff[N];
  for (int i = 0; i < N; ++i) {
    cin >> H[i]; 
    avetemp[i] = T - H[i] * 0.006;
  }
  int index = 0;
  for (int i = 1; i < N; ++i) { 
    if (abs(A - avetemp[i]) < abs(A - avetemp[index])) index = i;
  }
  
  cout << index + 1 << endl;  
}