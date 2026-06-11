#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,T;
  cin >> N >> T;
  
  vector<int>c(N);
  vector<int>t(N);
  int M = 1000;
  int m = 0;
  for (int i = 0; i < N; i++) {
    cin >> c.at(i) >> t.at(i);
    if (T >= t.at(i) && M >= c.at(i)){
      M = c.at(i);
      m++;
    }
  }
  if (m == 0){
    cout << "TLE" << endl;
    return 0;
  }
  cout << M << endl;
}

  
  
 