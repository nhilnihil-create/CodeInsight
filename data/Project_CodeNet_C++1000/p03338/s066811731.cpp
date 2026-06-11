#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a=0; cin>>n;
  string s,x,y; cin>>s;
  for(int i=1; i<n; i++){
    int cnt=0;
    x=s.substr(0,i);
    y=s.substr(i);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    for(char c:x) if(count(y.begin(),y.end(),c)>0) cnt++;
    a=max(a,cnt);
  }
  cout<<a;
}