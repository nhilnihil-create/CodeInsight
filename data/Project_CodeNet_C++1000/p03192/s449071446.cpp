#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int i,res=0;
  for(i=0;i<s.length();i++) if(s[i]=='2') res++;
  cout<<res;
  return 0;
}