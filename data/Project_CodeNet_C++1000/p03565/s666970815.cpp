#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll INF = pow(10,9)+7;

int main(){
  string s,t;
  cin >> s >> t;
  int u = s.size() - 1;
  int n=t.size()-1;
  int next = u-1;
  while(u>=0){
    if(s[u]==t[n] || s[u]=='?') n--;
    else{
      n=t.size()-1;
      u=next;
      next=u-1;
      continue;
    } 
    if(n<0){
      break;
    }
    u--;
  }
  
  
  if(u<0){
    cout << "UNRESTORABLE" << endl;
  }
  else{
    string ans="";
    int i=0;
    while(i<s.size()){
      if(i==u){
        ans+=t;
        i+=t.size();
      }
      else if(s[i]=='?'){
        ans+='a';
        i++;
      }
      else{
        ans+=s[i];
        i++;
      }
    }
    cout << ans << endl;
  }
}