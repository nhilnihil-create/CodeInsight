#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  int cnt = 0, min = -1;
  for (auto x : A) {
    cnt = 0;
    while (x%2==0) {
      x /= 2;
      cnt++;
    }
    if (min==-1) min = cnt;
    if (cnt<=min) min = cnt;
  }
  
  cout << min << endl;

  return 0;
}
