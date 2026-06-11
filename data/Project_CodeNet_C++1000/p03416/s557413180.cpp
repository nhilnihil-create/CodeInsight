#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >>A>>B;

  int z=0;

  while (A<=B){
    if((A%10==A/10000)&&((A/1000)%10==((A/10)%10))){
    z++;
    }
    
    A++;
  }

  cout <<z<<endl;

}
