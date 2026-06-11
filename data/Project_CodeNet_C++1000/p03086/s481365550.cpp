#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string S;
  cin>>S;
  vector<char> s(S.length());
  for(int i=0;i<S.length();i++){
    s[i]=S.at(i);
  }
  int cnt=0;
  int ans=0;
  for(int i=0;i<S.length();i++){
    if(s[i]=='A'){
      cnt++;
      continue;
    }
    if(s[i]=='C'){
      cnt++;
      continue;
    }
    if(s[i]=='G'){
      cnt++;
      continue;
    }
    if(s[i]=='T'){
      cnt++;
      continue;
    }
    else{
      if(ans<cnt){
        ans=cnt;
      }
      cnt=0;
    }
  }
  if(ans<cnt){
    ans=cnt;
  }
  cout<<ans<<endl;
}