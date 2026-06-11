#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,j = 0;
  int P = 1;
  cin >> N >> K;
  while(j<N){
    if(P*2 < (P+K)){
      P *= 2;
    }
    else{
      P += K;
    }
    j++;
  }
  
    cout << P << endl;
}