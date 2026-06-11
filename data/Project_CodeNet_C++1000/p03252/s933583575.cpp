#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s,t;
  cin>>s>>t;
  int n = s.size();
  map<char,char> mp1,mp2;
  char tmp='a';
  rep(i,26){
    mp1[tmp]='#';
    mp2[tmp]='#';
    tmp++;
  }
  bool ans=1;
  rep(i,n){
    if(t[i]==mp1[s[i]] || mp1[s[i]]=='#') mp1[s[i]]=t[i];
    else ans=0;
    if(s[i]==mp2[t[i]] || mp2[t[i]]=='#') mp2[t[i]]=s[i];
    else ans=0;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
