#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  int A,B,K,s;
  cin >> A >> B >> K;
  s = B - A + 1;
  
  if(s <= 2*K)  for(int i=A;i<=B;i++){ cout << i << endl; }
  else{
      for(int i=A;i<(A+K);i++) cout << i << endl;
      for(int i=(B-K+1);i<=B;i++) cout << i << endl;
  }
}
