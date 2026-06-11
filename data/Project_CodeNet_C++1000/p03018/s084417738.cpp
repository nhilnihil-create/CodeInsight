#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  string T="";
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='A'){
      T+='A';
      continue;
    }
    if(i+1<S.size()){
      if(S.at(i)=='B' && S.at(i+1)=='C'){
        T+='D';
        i++;
        continue;
      }
    }
    T+='E';
  }
  long long ans=0;
  long long cntA=0;
  for(int i=0;i<T.size();i++){
    if(T.at(i)=='A')  cntA++;
    else if(T.at(i)=='D') ans+=cntA;
    if(T.at(i)=='E')  cntA=0;
  }
  cout << ans << endl;
  
  return 0;
}
