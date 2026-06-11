#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,max;
  cin >> N >> M;
  
  
  for(int i=M/N+1; i >0; i--){
    if(M%i==0 && M/i >= N){
      max = i;
      break;
    }
  } 
  cout << max <<endl;
}