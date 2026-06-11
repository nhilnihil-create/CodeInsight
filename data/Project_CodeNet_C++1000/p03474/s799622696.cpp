#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,sum=0;
  cin >> A >> B;
  string S;
  cin >> S;
  if(S[A]=='-'){
    sum++;
    for(int i=0;i<A;i++){
      if(S[i]!='-'){
        sum++;
      }
    }
    for(int i=A+1;i<A+B+1;i++){
      if(S[i]!='-'){
        sum++;
      }
    }
  }
  if(sum==A+B+1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}