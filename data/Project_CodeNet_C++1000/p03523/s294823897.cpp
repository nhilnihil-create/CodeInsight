#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  if(s[0]!='A')s='A'+s;
  if(s.substr(0,4)!="AKIH"){
    cout<<"NO";
    return 0;
  }
  s=s.substr(4);
  if(s[0]!='A')s='A'+s;
  if(s.substr(0,2)!="AB"){
    cout<<"NO";
    return 0;
  }
  s=s.substr(2);
  if(s[0]!='A')s='A'+s;
  if(s.substr(0,2)!="AR"){
    cout<<"NO";
    return 0;
  }
  s=s.substr(2);
  if(s=="" || s=="A"){
    cout<<"YES";
  }else cout<<"NO";
}