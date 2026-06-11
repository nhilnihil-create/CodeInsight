#include<bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,K;
  cin >> A >> B >> K;
  for(int i=A;i<B+1;i++){
    if(i<=A+K-1){
      cout << i << endl;
    }else if(i>=B-K+1){
      cout << i << endl;
    }
  }
  return 0;
}