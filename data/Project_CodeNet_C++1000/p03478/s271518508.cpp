#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,sum=0,tmp,j;
  cin >> N >> A >> B;
  for(int i=1;i<N+1;i++){
    j=i;
    while(j>0){
      tmp += j%10;
      j = j/10;
    }
    if(tmp>=A && tmp <=B){
      sum += i;
    }
    tmp=0;
  }
  cout << sum << endl;
  return 0;
}