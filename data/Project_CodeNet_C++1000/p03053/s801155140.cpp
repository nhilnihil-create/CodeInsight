#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(x) x.begin(),x.end()
const ll MOD=1000000007;
const long double PI=3.14159265358979;

ll x[4]={0,0,1,-1};
ll y[4]={1,-1,0,0};

int main(){
  ll H,W;
  cin>>H>>W;
  ll Map[H][W];
  queue <pair<ll,ll>> q;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char s;
      cin>>s;
      if(s=='.'){
        Map[i][j]=MOD;
      }
      else{
        Map[i][j]=0;
        q.push({i,j});
      }
    }
  }
  while(!q.empty()){
    pair<ll,ll> p=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      if(p.first+x[i]==H||p.first+x[i]==-1||p.second+y[i]==W||p.second+y[i]==-1){
        continue;
      }
      if(Map[p.first+x[i]][p.second+y[i]]>Map[p.first][p.second]+1){
        Map[p.first+x[i]][p.second+y[i]]=Map[p.first][p.second]+1;
        q.push({p.first+x[i],p.second+y[i]});
      }
    }
  }
  ll ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      ans=max(ans,Map[i][j]);
    }
  }
  cout<<ans;
}