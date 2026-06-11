//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
  ll n,m; cin>>n>>m;
  Graph G(n);
  vector<ll>a(m),b(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  ll ans=0;
  rep(i,m){
    queue<ll>q;
    q.push(0);
    vector<bool>seen(n,false);
    seen[0]=true;
    while(!q.empty()){
      ll v=q.front();
      q.pop();
      for(auto nv:G[v]){
        if(v==a[i]&&nv==b[i])continue;
        else if(v==b[i]&&nv==a[i])continue;
        else if(seen[nv])continue;
        q.push(nv);
        seen[nv]=true;
      }
    }
    rep(i,n){
      if(seen[i]==false){
        ans++;
        break;
      }
    }
 }
 cout<<ans<<endl;
}






