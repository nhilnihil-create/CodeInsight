#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a=0; cin>>n;
  string s,x,y; cin>>s;
  for(int i=1; i<n; i++){
    int cnt=0;
    x=s.substr(0,i);
    y=s.substr(i);
    for(char c='a'; c<='z'; c++){
      if(count(x.begin(),x.end(),c)!=0 && count(y.begin(),y.end(),c)!=0) cnt++;
    }
    a=max(a,cnt);
  }
  cout<<a;
}