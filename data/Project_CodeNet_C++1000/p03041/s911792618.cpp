#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin>>N>>K;
  string S;cin>>S;
  char f=S.at(K-1);
  if(f=='A') S.at(K-1)='a';
  else if(f=='B') S.at(K-1)='b';
  else S.at(K-1)='c';
  cout<<S<<endl;
}