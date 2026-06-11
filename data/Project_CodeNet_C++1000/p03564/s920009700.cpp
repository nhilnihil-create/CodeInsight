#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, P,Q;
  cin >> N >> K;
  P=1;
  Q=1;
  while(N-Q>=0){
    if(P<K){
      P=P*2;
      Q++;
     }
  
  else if(P>=K){
    P=P+K;
    Q++;
   }
  }
  cout << P << endl;
}
