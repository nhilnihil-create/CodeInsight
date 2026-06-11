#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  if(s.size()==2)cout<<s;
  else{
    for(i=0;i<3;i++)cout<<s[2-i];
  }
}