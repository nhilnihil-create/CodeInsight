#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int ans=0;
  string s;
  cin>>s;
  rep(i,4){
    if(s[i]=='+')ans++;
    if(s[i]=='-')ans--;
  }
  cout<<ans<<endl;
  
  return 0;
}