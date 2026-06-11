#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  string cor="AKIHABARA";
  int c=0;
  bool f=true;
  rep(i, cor.size()){
    if(s[c]==cor[i]){
      c++;
    }else if(s[c]!=cor[c] && cor[i]!='A'){
      f=false;
      break;
    }
  }
  if(c!=s.size())f=false;

//cout<<c<<' '<<s.size()<<endl;

  if(f)cout<<"YES";
  else cout<<"NO";

  return 0;
}