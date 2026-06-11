#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main(){
  string s;
  cin>>s;
  string t="AC";
  if(s[0]!='A') t="WA";
  if(s[1]<'a') t="WA";
  if(s[s.size()-1]<'a') t="WA";
  int cnt=0;
  rep(i,2,s.size()-1){
    if(s[i]=='C') cnt++;
    else if(s[i]<'a') t="WA";
  }
  if(cnt!=1) t="WA";
  cout<<t<<endl;
}