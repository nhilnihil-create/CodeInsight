#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin>>N>>K;
  string S;cin>>S;

  for(int i=1; i<=N; i++){
    if(i==K){
      cout<<(char)(S[i-1]-'A'+'a');
    }else{
      cout<<S[i-1];
    }
  }
  cout<<endl;
}