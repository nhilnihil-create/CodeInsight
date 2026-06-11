#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,c=0;
  cin >> A >> B;
  for(A;A<B+1;A++){
    if(A/10000==(A-A/10*10)){
      if((A-A/10000*10000)/1000==(A-A/100*100)/10){
        c++;
      }
    }
  }
  cout << c << endl;
}