#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p=0,a=0;cin>>n;
  vector<int>s(n),c(1);for(int i=0;i<n;i++)cin>>s.at(i);c.at(0)=1;
  for(int i=1;i<n;i++){
    if(s.at(i)==s.at(i-1))c.at(p)++;
    else{c.push_back(1);p++;}
  }
  for(int i=0;i<=p;i++)a+=c.at(i)/2;
  cout<<a<<endl;
}

  
