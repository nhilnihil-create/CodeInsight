#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  for(int i=0;i<S.size();i++){
    if(i+1<S.size()){
      if(S.at(i)=='B' && S.at(i+1)=='C'){
        S.replace(i,2,"D");
      }
    }
  }
  
  long long cnt=0;
  long long atemp=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='A') atemp++;
    if(S.at(i)=='D'){
      cnt+=atemp;
    }
    if(S.at(i)=='B'||S.at(i)=='C'){
      atemp=0;
    }
  }
  
  cout<<setprecision(18)<<cnt<<endl;
  return 0;
}

    