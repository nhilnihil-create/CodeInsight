#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  
  int k = 1;
  for (int i = 0; i < N; i++) {
    k *= 3;
  }
  
  int pos = 1;
  for (int &e : A) {
    cin >> e;
    if (e % 2 == 0) pos *= 2;
  }
  
  cout << k - pos << endl;
}