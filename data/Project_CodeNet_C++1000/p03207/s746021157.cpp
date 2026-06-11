#include <bits/stdc++.h>
    using namespace std;
    
    int main() {
    int i = 0;
      int N;
      cin >> N;
      int D;
      int sum = 0;
      int Di = 0;
    while(i < N){
     cin >> D;
      sum += D;
     i++;
      if(Di < D) {
        Di = D;
      }
    }
      cout << sum - Di / 2 << endl;
    }