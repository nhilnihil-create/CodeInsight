#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  for(i=0;i<4;i++){
    if(s[i]=='2')cnt++;
  }
  cout<<cnt;
}