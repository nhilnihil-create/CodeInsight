#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N,K,Y;
  int X =1;
  cin >> N >> K;
  Y=0;
  for (;N>Y; Y++){
    if(X<K){
      X*=2;
    }
    else{
      X+=K;
    }
  }
  cout << X <<endl;
}