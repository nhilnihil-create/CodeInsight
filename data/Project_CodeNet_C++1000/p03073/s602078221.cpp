#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N = S.size();
  int a=0;
  int b=0;
  
  //10101にする
  for(int i=0; i<N; i++){
    if(i%2==0){
      if(S.at(i)=='0') a++;
    }
    else{
      if(S.at(i)=='1') a++;
    }
  }
  
  //0101にする
  for(int i=0; i<N; i++){
    if(i%2==0) {
      if (S.at(i)=='1') b++;
    }
    else {
      if(S.at(i)=='0') b++;
    }
  }
  
  cout<<min(a,b)<<endl;
}