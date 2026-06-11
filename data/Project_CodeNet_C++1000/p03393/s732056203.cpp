#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  if(S.size()==26){
    if(S=="zyxwvutsrqponmlkjihgfedcba")cout<<"-1"<<endl;
    else{
      int i=25;
      while(S.at(i)<S.at(i-1))i--;
      int j=25;
      while(S.at(i-1)>S.at(j))j--;
      S.at(i-1)=S.at(j);
      cout<<S.substr(0,i)<<endl;
    }
  }
  else{
    string T=S;
    sort(S.begin(),S.end());
    char a='a';
    while(binary_search(S.begin(),S.end(),a))a++;
    cout<<T+a<<endl;
  }
}