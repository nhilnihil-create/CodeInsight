#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  if (N==1) {
    cout << 1 << endl;
  }
  
  else {
    vector<int> A(N);
    for (int i=0; i<N; i++) {
      cin >> A.at(i);
    }
    
    sort(A.begin(),A.end());
    
    int H=1;
    for (int i=0; i<N-1; i++) {
      if (A.at(i)-A.at(i+1) < 0) {
        H++;
      }
    }
    
    cout << H << endl;
  }
}