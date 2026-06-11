#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,ans="";
  cin >> s;
  vector<bool>aru(26);
  if(s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0;i<s.size();i++)
    aru.at(s.at(i)-'a')=true;
  bool ok=false;
  for(int i=0;i<26;i++){
    if(!aru.at(i)){
      ans=s;
      ans+=i+'a';
      ok=true;
      break;
    }
  }
  if(!ok){
    for(int i=24;i>=0;i--){
      if(s.at(i+1)>s.at(i)){
        if(i==0){
          ans+=s.at(0)+1;
          break;
        }
        ok=true;
        for(int j=0;j<i;j++){
          ans+=s.at(j);
        }
        vector<bool>deta(26,false);
        for(int j=0;j<ans.size();j++)
          deta.at(ans.at(j)-'a')=true;
        deta.at(s.at(i)-'a')=true;
        for(int j=s.at(i)-'a';j<26;j++){
          if(!deta.at(j)){
            ans+='a'+j;
            break;
          }
        }
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}