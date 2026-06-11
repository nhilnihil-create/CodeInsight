#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,p,kekka = 1;
  cin >> n >> p;
  long m = p;
  for(long i = 2;i*i <= m;i++){
    long c = 0;
    for(long j = 0;j > -1;j++){
      if(p % i == 0){
        p /= i;
        c++;
      }
      else{
        break;
      }
    }
    if(c >= n){
      for(long k = 0;k < c/n;k++){
        kekka *= i;
      }
      //cout <<c << " " << i << endl;
    }
  }
  if(n == 1){
    cout << kekka*p << endl;
  }
  else{
    cout << kekka << endl;
  }
}