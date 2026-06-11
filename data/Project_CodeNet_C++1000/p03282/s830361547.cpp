#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int64_t k,n,c=0;
  cin>>s>>k;
  n=s.length();
  if(s.at(0)!='1') cout<<s.at(0)<<endl;
  else{
    while(c<n&&s.at(c)=='1') c++;
    if(k<=c) cout<<'1'<<endl;
    else cout<<s.at(c)<<endl;
  }
}