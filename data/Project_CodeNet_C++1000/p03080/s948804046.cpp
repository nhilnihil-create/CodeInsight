#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  cin>>N>>s;
  int r=0;
  for(char &c:s)
    if(c=='R')
      r++;
  if(r>N-r)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}