#include <bits/stdc++.h>
using namespace std;


int main() {
  string S;
  cin>>S;
  int N=S.size();
    
  
  vector<char> a(N,'0');
  vector<char> b(N,'0');
  if(N%2==0){
    for(int i=0;i<N/2;i++){
      a.at(2*i)='1';
      b.at(2*i+1)='1';
    }
  }
  else{
    for(int i=0;i<N/2;i++){
      a.at(2*i)='1';
      b.at(2*i+1)='1';
      a.at(N-1)='1';
    }
  }
  
  int suma=0;
  for(int i=0;i<N;i++){
    if(S.at(i)!=a.at(i)) suma++;
  }
  int sumb=0;
   for(int i=0;i<N;i++){
    if(S.at(i)!=b.at(i)) sumb++;
  }
  if(N==1) cout<<0<<endl;
  else cout<<min(suma,sumb)<<endl;
 
  
}