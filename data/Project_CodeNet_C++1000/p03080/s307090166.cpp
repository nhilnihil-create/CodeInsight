#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;string S;cin>>N>>S;
  if(count(S.begin(),S.end(),'R')>count(S.begin(),S.end(),'B'))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}