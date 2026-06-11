#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<pair<int,int>> E;
vector<int> to[60];
bool seen[60];

void go(int a,int b,int v){
  for(auto w : to[v]){
    if(seen[w])continue;
    if(a==w&&b==v)continue;
    if(a==v&&b==w)continue;
    seen[w]=true;
    go(a,b,w);
  }
}

int main() {
  int n,m;
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
    E.push_back(make_pair(a,b));
  }
  int ans=0;
  for(auto e : E){
    rep(i,n){
      seen[i]=false;
    }
    seen[0]=true;
    int a,b;
    tie(a,b)=e;
    go(a,b,0);
    rep(i,n){
      if(!seen[i]){
        ans++;
        break;
      }
    }
  }
  cout<<ans<<endl;
}