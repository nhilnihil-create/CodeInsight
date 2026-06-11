#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int>b(N);
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin >> b.at(i);
  }
  
  for (int j = 0; j < N; j++) {
    for (int i = N-1-j; i >= 0; i--) {
      if (b.at(i) == i + 1){
        a.at(N-j-1) = b.at(i);
        for (int k = i; k < N-j-1; k++) {
          b.at(k) = b.at(k+1);
        }
        break;
      }
      else if (i == 0){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    cout << a.at(i) << endl;
  }
}
    
      