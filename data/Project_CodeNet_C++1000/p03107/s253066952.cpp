#include <bits/stdc++.h>
using namespace std;


int main() {
  string S;
  cin>>S;
  int N=S.size();
  
  int sumz=0;
  int sumn=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='0') sumz++;
    else sumn++;
  }
  cout<<2*min(sumz,sumn)<<endl;
  
}