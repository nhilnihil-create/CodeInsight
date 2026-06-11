#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int kansu(string t,string u){
  int ans=0;
  for(char c='a';c<='z';c++){
    bool is_t=false,is_u=false;
    for(int i=0;i<t.size();i++){
      if(t.at(i)==c){
        is_t=true;
      }
    }
    for(int i=0;i<u.size();i++){
      if(u.at(i)==c){
        is_u=true;
      }
    }
    if(is_t && is_u){
      ans++;
    }
  }
  return ans;
}
int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans=0;
  rep(i,n-1){
    int p;
    string t,u;
    t=s.substr(0,i);
    u=s.substr(i);
    p=kansu(t,u);
    ans=max(ans,p);
  }
  cout << ans;
}
    