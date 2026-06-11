#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A = 0, B = 0;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  for (int j = 0; j < N; j++) {
    if (j % 2 == 0) {
      A += a.at(j);
    }
    else {
      B += a.at(j);
    }
  }
  cout << A - B << endl;
}