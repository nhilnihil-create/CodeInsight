#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  int N,r=0,b=0;
  string s;
  cin>>N>>s;
  for(char i:s){
    if(i=='R')r++;
    else b++;
  }
  if(r>b)cout<<"Yes"<<"\n";
  else cout<<"No"<<"\n";
}