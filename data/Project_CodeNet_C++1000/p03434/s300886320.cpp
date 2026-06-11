#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Alice, Bob;
  int max, l;
  cin >> N;
  
  vector<int> a(N);
  
  for(int i = 0; i < N ; i++) {
     cin >> a.at(i);
  }
  
  Alice = 0;
  Bob = 0;
  for(int i = 0; i < N ; i++) {
    max = 0;
    for(int j = 0; j < N; j++) {
      if(max < a.at(j)) {
        max = a.at(j);
        l = j;
      }
    }
    Alice += a.at(l);
    a.at(l) = 0; 
    
    max = 0;
    for(int k = 0; k < N; k++) {
      if(max < a.at(k)) {
        max = a.at(k);
        l = k;
      }
    }
    Bob += a.at(l);
    a.at(l) = 0;
  }
  if(Alice-Bob > 0) {
    cout << Alice-Bob << endl;
  }
  else {
    cout << Bob-Alice << endl;
  }
}
