#include<bits/stdc++.h>
using namespace std;

int q(char x){
  if(x=='0' ||x=='1' ||x=='2' ||x=='3' ||x=='4' ||x=='5' ||x=='6' ||x=='7' ||x=='8' ||x=='9'){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  int A,B;
  cin >> A>>B;
  int ans=0;
  string S;
  cin >> S;
  
  for(int i=0;i<A;i++){
    if(q(S[i])==0){
      ans ++;
    }
  }
  if(S[A]!='-'){
    ans ++;
  }
  for(int i=A+1;i<B+A+1;i++){
    if(q(S[i])==0){
      ans ++;
    }
  }
  
  if(ans == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
      
}