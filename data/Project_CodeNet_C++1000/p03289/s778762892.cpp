#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  string ans="AC";
  int big=0;
  for(int i=0;i<n;i++){
    if(i==0) {
      if(s[i]!='A') ans="WA";
    }
    else if(i==1 || i==n-1){
      if(s[i]-'a'<0 || s[i]-'a'>25) ans="WA";
    }
    else{
      if(s[i]-'a'<0 || s[i]-'a'>25){
        big++;
        if(s[i]!='C') ans="WA";
      }
    }
  }
  if(big!=1) ans="WA";
  cout<<ans<<endl;
  }
