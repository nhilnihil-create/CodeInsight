#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  int count = 0;
  int max = 101;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < max) {
      count++;
      max = A.at(i);
    }
  }
  
  cout << count << endl;
}