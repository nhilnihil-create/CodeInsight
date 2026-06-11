#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  
  vector<int> A(26,-1),B(26,-1);
  
  bool b=true;
  rep(i,s.size()){
    if(A[s[i]-'a']==-1) A[s[i]-'a']=t[i]-'a';
    else if(A[s[i]-'a']!=t[i]-'a'){
      b=false;
      break;
    }
  }
  rep(i,t.size()){
    if(B[t[i]-'a']==-1) B[t[i]-'a']=s[i]-'a';
    else if(B[t[i]-'a']!=s[i]-'a'){
      b=false;
      break;
    }
  }
  if(b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}