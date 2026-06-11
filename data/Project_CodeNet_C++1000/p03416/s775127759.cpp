#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A,B,X,c=0;
  cin >> A >> B;
  X = A;
  
  rep(i,B-A+1){
    if(X/10000 == X%10 && (X%10000)/1000 == (X%100)/10){
      c += 1;
    }
    
    X += 1;
  }
  cout << c << endl;
}
