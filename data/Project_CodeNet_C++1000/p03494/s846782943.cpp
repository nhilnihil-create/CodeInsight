#include <bits/stdc++.h>
using namespace std;

int count(int x){
  int m = 0;
  while(x%2==0){
    x /= 2;
    m++;
  }
  return m;
}

int main(){
  int N,n,A[201],max;
  
    cin >> N>> A[1];
    max = count(A[1]);
  for(n=2;n<=N;n++){
    cin >> A[n];
    if(count(A[n]) < max) max = count(A[n]);
  }
  cout << max << endl;
}