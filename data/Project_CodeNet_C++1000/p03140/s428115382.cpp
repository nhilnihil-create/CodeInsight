#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0; cin>>n;
  vector<string> s(3); cin>>s[0]>>s[1]>>s[2];
  for(int i=0;i<n;i++){
    if(s[0][i]==s[1][i]){
      if(s[0][i]!=s[2][i]) ans++;
    }else if(s[1][i]==s[2][i]){
      ans++;
    }else if(s[0][i]==s[2][i]){
      ans++;
    }
    else ans+=2;
  }
  cout<<ans<<endl;
}