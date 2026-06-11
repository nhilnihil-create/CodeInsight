#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s,t;
  cin>>s>>t;
  int index=-1;
  for(int i = 0; i < s.size()-t.size()+1; i++){
    bool ok=1;
    for(int j = 0; j < t.size(); j++){
      if(s[i+j] != t[j] && s[i+j] != '?') ok=0;
    }
    if(ok) index = i;
  }
  if(index==-1) cout<<"UNRESTORABLE"<<endl;
  else{
    string ans;
    int tmp=0;
    for(int i = 0; i < s.size(); i++){
      if(i >= index && index+t.size() > i){
        ans+=t[tmp];
        tmp++;
      }else{
        if(s[i]=='?') ans+='a';
        else ans+=s[i];
      }
    }
    cout<<ans<<endl;
  }
}

