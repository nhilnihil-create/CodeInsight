#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  bool ans=true;
  if(s[0]!='A')ans=false;
  int cnt=0;
  for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C')cnt++;
  }
  if(cnt!=1)ans=false;
  int a=0;
  rep(i,s.size()){
    if(islower(s[i]))a++;
  }
  if(s.size()-a!=2)ans=false;
  if(ans)cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}