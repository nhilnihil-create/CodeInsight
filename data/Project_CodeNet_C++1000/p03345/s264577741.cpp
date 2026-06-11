#include <bits/stdc++.h>
using namespace std;



int main() {
  long long A,B,C,K;
  
  cin >> A >> B >> C >> K;
  if(K%2 == 0){
    if(abs(A-B) > pow(10,18)){
      cout << "Unfair" << endl;
    }else{
      cout << A-B << endl;
    }
  }else{
    if(abs(B-A) > pow(10,18)){
      cout << "Unfair" << endl;
    }else{
      cout << B-A << endl;
    }
  }
  
  return 0;
}
