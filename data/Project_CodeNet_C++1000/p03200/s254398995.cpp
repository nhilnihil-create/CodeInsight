#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll=long long;
int main(){

  string S;
  cin>>S;
  ll count=0;
  for(size_t i=0;i<=S.length()-1;i++){
  
    if(S[i]=='W')count++;
    else break;
  }
  ll level=0;
  ll ans=0;
  for(size_t i=count;i<=S.length()-1;i++){
    
    if(S[i]=='W'){
    
      ans+=i-count-level;
      level++;
    }
  }
  cout<<ans;
}