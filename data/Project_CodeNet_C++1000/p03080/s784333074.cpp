#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>S;
  int r=0,b=0;
  for(int i=0;i<S.size();i++)
    if(S[i]=='R')
      r++;
    else
      b++;
  if(b<r)
    cout<<"Yes";
  else
    cout<<"No";
  cout<<endl;
  
  return 0;
}