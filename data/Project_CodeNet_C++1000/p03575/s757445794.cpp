#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  P path[m];
  vector<int> edge[n];
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    path[i]=P(a-1,b-1);
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
  }
  int ans=0;
  rep(i,0,m){
    bool p[n];
    rep(i,0,n) p[i]=false;
    p[0]=true;
    queue<int> q;
    q.push(0);
    while(q.size()){
      int r=q.front();
      q.pop();
      for(int s:edge[r]){
        if(P(r,s)!=path[i] && P(s,r)!=path[i] && !p[s]){
          p[s]=true;
          q.push(s);
        }
      }
    }
    int j=1;
    rep(i,0,n){
      if(!p[i]) j=0;
    }
    ans+=j;
  }
  cout<<m-ans<<endl;
}