#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B;
  C = 0;
  for (int i; i<B+1 ;i++){
    if (i != 0){
      if((i/1000 + i%100)%11 ==0 && i/10000==i%10){
        C++;
      }
    }else{
      i = A-1;
    }
  }
    cout << C << endl;
}
