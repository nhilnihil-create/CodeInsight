#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,h;
  cin>>n>>c;
  h=100000;
  vector<vector<int>> d(c,vector<int>(h,0));
  for(int _=0;_<n;_++){
    int s,t,ci;
    cin>>s>>t>>ci;
    s--;
    t--;
    ci--;
    d.at(ci).at(s)++;
    d.at(ci).at(t)--;
  }
  int r=0;
  int m=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<c;j++)
      r+=max(d.at(j).at(i),0);
    m=max(m,r);
    for(int j=0;j<c;j++)
      r+=min(d.at(j).at(i),0);
  }
  cout<<m<<endl;
}