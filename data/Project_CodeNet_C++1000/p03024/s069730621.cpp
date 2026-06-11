#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int j=0;
  for(char c:S)
    if(c=='o')
      j++;
  if(15-S.size()+j<8)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
}