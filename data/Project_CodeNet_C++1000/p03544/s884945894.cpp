#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long Y=1;
  long long Z=3;
  cin >> N;
  if(N==1){
    cout << 1 << endl;
  }
  else if(N==2){
    cout << 3 << endl;
  }
  else{
    for (int X=0;X<N-3;X++){
      if (Y<Z){
        Y+=Z;
      }
      else{
        Z+=Y;
      }
    }
    cout << Y+Z << endl;
  }
}