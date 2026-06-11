#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A ,B,sum = 0,n = 0,m = 0;
  cin >> N >> A >> B;


  for(int i = 1; i <= N; i++){
    n = i;
    while(n != 0){
      m += n%10;
      n /= 10;
    }
    if(A <= m && m <= B){
      sum += i;
    }
    m = 0;
  }
  cout << sum << endl;
  return 0;
}