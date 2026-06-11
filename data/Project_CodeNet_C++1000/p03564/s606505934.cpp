#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
  int N , K, C=1;
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) { 

	if (C * 2 <= C+K){
      C = C*2;
    }
    else if (C * 2 > C+K){
      C += K ;
    }

  }

  cout << C << endl;

}
