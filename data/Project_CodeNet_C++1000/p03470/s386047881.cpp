#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int sum=1;
  
  vector<int> d(N);
  for (int i=0; i<N; i++) {
    cin >> d.at(i);
  }
  
  int a=0;
  
  for (int i=0; i<N; i++) {
    if (a < d.at(i)) {
      a=d.at(i);
    }
  }
  
  for (int i=0; i<N; i++) {
    int b=0;
    
    for (int j=0; j<N; j++) {
      if (b < d.at(j) && d.at(j) < a) {
        b = d.at(j);
      }
    }
    
    if (b != 0) {
      sum++;
      a = b;
    }
    else {
      break;
    }
  }
  cout << sum << endl;
}