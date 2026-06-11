#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  string S="";
  if(N==0){
    S="0";
  }
  while(N!=0){
    if(N%2!=0){
      N--;
      S.push_back('1');
    }
    else{
      S.push_back('0');
    }
    N/=-2;
  }
  reverse(S.begin(),S.end());
  cout<<S<<endl;
}

