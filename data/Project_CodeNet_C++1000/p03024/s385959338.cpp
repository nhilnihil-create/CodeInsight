#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;int n=s.size(),w=0;
  for(int i=0;i<n;i++){if(s.at(i)=='o')w++;}
  if(w+15-n<8)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}