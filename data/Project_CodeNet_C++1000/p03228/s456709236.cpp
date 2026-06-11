#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;
  cin >> A >> B >> K;
  
  for(int k=0; k<K; k++){
    if(k%2==0){
      if(A%2 != 0){ A--; }
      int diff= A/2;
      A-= diff;
      B+= diff;
    }
    else{
      if(B%2 != 0){ B--; }
      int diff= B/2;
      B-= diff;
      A+= diff;
    }
  }

  cout << A <<" "<< B << endl;
}