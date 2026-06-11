#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin>>N>>K>>S;
  S[K-1]=(char)(S[K-1]-('A'-'a'));
  cout<<S<<endl;
}