#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,c=0;cin>>n>>m;
  if(n>=m)return cout<<0,0;
  vector<int> x(m),s(m-1);
  for(int i=0;i<m;++i)cin>>x[i];
  sort(x.begin(),x.end());
  for(int i=0;i<m-1;++i)s[i]+=(x[i+1]-x[i]),c+=s[i];
  sort(s.begin(),s.end(),greater<int>());
  n--;
  for(int i=0;i<n;++i)c-=s[i];
  cout<<max(c,0);
}