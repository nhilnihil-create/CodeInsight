#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int A,B,C=0,D=0;
  string S;
  cin >> A;
  cin >> S;
  for(int i=0;i<A;i++){
    if(S[i]=='R')C++;
    else if(S[i]=='B')D++;
  }
  if(C>D)cout << "Yes" << endl;
  else cout << "No" << endl;
}
  
    
