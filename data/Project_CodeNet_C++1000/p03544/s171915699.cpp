#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> V(N+1, 0);
  
  for (int i = 0; i <= N; i++) {
    if (i==0) {
      V.at(i) = 2;
    }
    else if (i==1) {
      V.at(i) = 1;
    }
    else {
      V.at(i) = V.at(i-1) + V.at(i-2);
    }
    //cout << V.at(i) << endl;
  }
  cout << V.at(N) << endl;
}
