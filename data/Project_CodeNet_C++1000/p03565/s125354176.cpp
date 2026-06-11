#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  bool ok=true;
  vector<int>start;
  for(int i=0;i<s.size()-t.size()+1;i++){
    ok=true;
    for(int j=0;j<t.size();j++){
      if(s.at(i+j)!=t.at(j)&&s.at(i+j)!='?') ok=false;
    }
    if(ok) start.push_back(i);
  }
  if(start.size()==0){
    cout << "UNRESTORABLE\n";
  }else{
    string now="",ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i=0;i<start.size();i++){
      now="";
      for(int j=0;j<start.at(i);j++){
        now+=(s.at(j)=='?'?'a':s.at(j));
      }
      now+=t;
      for(int j=start.at(i)+t.size();j<s.size();j++){
        now+=(s.at(j)=='?'?'a':s.at(j));
      }
      ans=min(ans,now);
    }
    cout << ans << endl;
  }
  return 0;
}