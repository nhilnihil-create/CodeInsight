#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string> W(N);
  for (int i=0 ; i<N ; i++) {
    cin >> W.at(i);
  }
  
  int judge1 = N;
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if ( W.at(i) == W.at(j) ) {
        judge1 = judge1 - 1;
      }
    }
  }
  
  int judge2 = N-1;
  
  for (int i=0; i<N-1; i++) {
    if (W.at(i).at(W.at(i).size()-1) == W.at(i+1).at(0)) {
     judge2 = judge2 - 1; 
    }
  }
  
  if (judge1 == 0 && judge2 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
    
}
  
  
  