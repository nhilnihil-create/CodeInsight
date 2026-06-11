#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,ans=0;
  cin>>n>>m;
  vector<int> a(m),b(m);
  vector<vector<int>> g(n);
  for(i=0;i<m;i++){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
    g.at(a.at(i)).push_back(b.at(i));
    g.at(b.at(i)).push_back(a.at(i));
  }
  for(i=0;i<m;i++){
    queue<int> q;
    vector<int> f(n,-1);
    q.push(a.at(i));
    f.at(a.at(i))=0;
    while(!q.empty()){
      int x=q.front();
      q.pop();
      for(auto z:g.at(x)){
        if(x==a.at(i)&&z==b.at(i)) continue;
        if(f.at(z)>-1) continue;
        f.at(z)=f.at(x)+1;
        q.push(z);
      }
    }
    if(f.at(b.at(i))==-1) ans++;
  }
  cout<<ans<<endl;
}