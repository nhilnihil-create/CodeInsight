#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  int w;
  cin>>s;
  cin>>w;
  string t="";
  for(i=0;w*i<s.size();i++)t+=s[w*i];
  cout<<t;
}