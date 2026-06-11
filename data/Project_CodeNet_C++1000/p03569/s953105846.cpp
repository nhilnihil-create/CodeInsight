#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=0;
  for(int l=0,r=s.size()-1;l<=r;l++,r--){
    if(s[l]==s[r])
      continue;
    if(s[l]=='x'){
      for(;s[l]=='x';l++){
        ans++;
        if(l>r){
          puts("-1");
          return 0;
        }
      }
      if(s[l]!=s[r]){
        puts("-1");
        return 0;
      }
    }else if(s[r]=='x'){
      for(;s[r]=='x';r--){
        ans++;
        if(l>r){
          puts("-1");
          return 0;
        }
      }
      if(s[l]!=s[r]){
        puts("-1");
        return 0;
      }
    }else{
      puts("-1");
      return 0;
    }
  }
  cout<<ans<<endl;
}