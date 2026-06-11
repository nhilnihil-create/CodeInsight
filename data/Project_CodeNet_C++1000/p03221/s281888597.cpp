#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>>c(m,vector<int>(3));
  for(int i=0;i<m;i++){
    cin>>c[i][0]>>c[i][1];
    c[i][2]=i;
  }
  sort(c.begin(),c.end());
  vector<string>ans(m);
  int now=0;
  int pre=c[0][0];
  for(int i=0;i<m;i++){
    if(pre==c[i][0]){
      now++;
      string s2=to_string(now);
      int x=6-s2.size();
      for(int j=0;j<x;j++){
        s2="0"+s2;
      }
      string s1=to_string(c[i][0]);
      int y=6-s1.size();
      for(int j=0;j<y;j++){
        s1="0"+s1;
      }
      ans[c[i][2]]=s1+s2;
    }
    else{
      now=1;
      pre=c[i][0];
      string s2=to_string(now);
      int x=6-s2.size();
      for(int j=0;j<x;j++){
        s2="0"+s2;
      }
      string s1=to_string(c[i][0]);
      int y=6-s1.size();
      for(int j=0;j<y;j++){
        s1="0"+s1;
      }
      ans[c[i][2]]=s1+s2;
    }
  }
  for(int i=0;i<m;i++) cout<<ans[i]<<endl;
}