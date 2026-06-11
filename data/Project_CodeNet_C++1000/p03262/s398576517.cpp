#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b){
  
  if(a % b == 0) return b;
  else return GCD(b, a % b);
}

int main(){
  
  long long N, X, i, j, d, yk;
  cin >> N >> X;
  
  for(i = 0; i < N; i++){
    
    cin >> d;
    d = abs(d - X);
    if(i == 0) yk = d;
    if(d % yk == 0){
      continue;
    }else{
      yk = GCD(d, yk);
    }
  }
  cout << yk << endl;
  return 0;
}