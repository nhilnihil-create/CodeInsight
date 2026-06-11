#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  int i=0,j=s.size()-1,ans=0;
  while(i!=j){
    if(s[i]!=s[j]){
      if(s[i]=='x'){
        ans++; i++;
      }else if(s[j]=='x'){
        ans++; j--;
      }else{
        cout<<-1<<endl;
        return 0;
      }
    }else{
      i++;
      if(i==j) break;
      j--;
    }
  }
  cout<<ans<<endl;
}