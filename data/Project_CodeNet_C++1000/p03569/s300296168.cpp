#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  int result=0;

  int l=0, r = s.size()-1;
  while(r>l){
    if(s[l]==s[r]){
      l++;
      r--;
      continue;
    }
    if(s[l]!=s[r]){
      if(s[l]=='x'){
        l++;
        result++;
      }else if(s[r]=='x'){
        r--;
        result++;
      }else{
        cout<<-1<<endl;return 0;
      }
    }
//cout<<l<<' '<<r<<endl;
  }

  cout<<result<<endl;

  return 0;
}