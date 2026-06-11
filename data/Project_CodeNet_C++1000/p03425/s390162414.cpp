#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<char> x={'M','A','R','C','H'};
  vector<int64_t> c(x.size(),0);
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<x.size();j++)
      if(s.at(0)==x.at(j))
        c.at(j)++;
  }
  int64_t a=0;
  for(int i=0;i<c.size();i++)
    for(int j=i+1;j<c.size();j++)
      for(int k=j+1;k<c.size();k++)
        a+=c.at(i)*c.at(j)*c.at(k);
  cout<<a<<endl;
}