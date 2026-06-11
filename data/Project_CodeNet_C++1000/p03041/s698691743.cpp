#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin>>N>>K;
  string S;cin>>S;
  char f=S.at(K-1);
  S.at(K-1)=f+'a'-'A';
  cout<<S<<endl;
}
