#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >>s;
  int cnt=0,n=s.size();
  for(int i=0;i<n;i++){
    if(s[i-1]==s[i] && s[i]==s[i+1]){
      cnt++;
      if(s[i]=='0')s[i+1]='1';
      else s[i+1]='0';
    }else if(s[i]==s[i+1]){
      cnt++;
      if(s[i]=='0')s[i+1]='1';
      else s[i+1]='0';
    }
  }
  cout << cnt << endl;
}