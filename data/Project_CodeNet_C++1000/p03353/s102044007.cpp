#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  map<string,int>mp;
  for(int i=0;i<s.size();i++){
    for(int j=1;j<=min((int)s.size()-i,5);j++){
      string tmp=s.substr(i,j);
      //cout<<tmp<<endl;
      mp[tmp]++;
    }
  }
  int cnt=0;
  for(auto v:mp){
    cnt++;
    if(cnt==n){
      cout<<v.first<<endl;
    }
  }
}