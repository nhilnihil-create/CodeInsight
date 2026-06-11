#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  string s;
  cin>>n;
  cin>>s;
  int r=0,b=0;
  for(i=0;i<n;i++){
    if(s[i]=='R')r++;
    else b++;
  }
  if(r>b)cout<<"Yes";
  else cout<<"No";
}