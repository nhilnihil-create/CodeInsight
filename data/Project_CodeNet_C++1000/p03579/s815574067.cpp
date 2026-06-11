#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
int n,m;
cin>>n>>m;
vector<int> hen[n];
int a,b;
for(int i=0;i<m;i++){
  cin>>a>>b;a--;b--;
  hen[a].push_back(b);
  hen[b].push_back(a);
}
int p[n]={};
queue<int> que;
p[0]=1;
que.push(0);int t,ans=0;
while(!que.empty()){
  t=que.front();
  que.pop();
  for(int i=0;i<hen[t].size();i++){
    if(p[hen[t][i]]==0){
      p[hen[t][i]]=-1*p[t];
      que.push(hen[t][i]);
    }
    if(p[t]==p[hen[t][i]])ans=1;
  }
}
if(ans)cout<<n*(n-1)/2 -m;
else{
  int o=0;
  for(int i=0;i<n;i++){
    if(p[i]==1)o++;
  }
  cout<<o*(n-o)-m;
}


return 0;
}
