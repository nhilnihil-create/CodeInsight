#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,c=0,d=0,e=0,f=0,g=0;cin>>a;
  string b;
  rep(i,a){
    cin>>b;
     if(b.at(b.size()-1)=='A'&&b.at(0)=='B')e++;
    else if(b.at(0)=='B')f++;
    else if(b.at(b.size()-1)=='A')g++;
    for(int o=0;o<b.size()-1;o++){
      if(b.at(o)=='A'&&b.at(o+1)=='B')c++;
    }
  }
  if(e>=1&&f==0&&g==0)c--;
  cout<<c+min(e+g,f+e);
}