#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  string s,t; cin>>s>>t;
  int n=s.size(),m=t.size();
  vector<string> v;
  rep(i,n-m+1){
    bool b=true;
    for(int j=i; j<i+m; j++){
      if(s[j]!='?'&&s[j]!=t[j-i]){b=false;break;}
    }
    if(b){
      string s_="";
      rep(k,n){
        if( k >=i && k <i+m ){s_+= t[k-i];}
        else if(s[k]=='?'){s_+='a';}
        else{s_+=s[k];}
      }
      v.push_back(s_);
    }
  }
  if(v.size()==0){cout<<"UNRESTORABLE";}
  else{
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;
  }
}