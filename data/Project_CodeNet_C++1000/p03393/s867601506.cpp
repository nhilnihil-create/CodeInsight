#include <bits/stdc++.h>
using namespace std;
int main(){
  string s; cin>>s; bool finish=false;
  for(int i='a'; i<'z'; i++){
    for(int j=0; j<s.size(); j++){
      if(s[j]==i) break;
      if(j==s.size()-1){
        finish=true;
        s.push_back(i);
      }
    }
    if(finish) break;
  }
  string t=s;
  if(finish==false){
    if(s=="zyxwvutsrqponmlkjihgfedcba") s="-1";
    else{
      next_permutation(s.begin(), s.end());
      for(int i=0; i<s.size(); i++){
        if(s[i]!=t[i]) s.erase(s.begin()+i+1, s.end());
      }
    }
  }
  cout<<s<<endl;
}
