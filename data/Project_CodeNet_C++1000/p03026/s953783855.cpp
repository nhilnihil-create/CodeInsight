#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a,b;cin>>n;
  vector<lvector> G(n);
  lvector c(n),ans(n),deg(n);
  lque deg1;
  rep(i,n-1) {
    cin>>a>>b;a--,b--;
    G[a].emplace_back(b);G[b].emplace_back(a);
  }
  rep(i,n) {
    deg[i]=G[i].size();
    if(deg[i]==1) deg1.push(i);
  }
  rep(i,n) cin>>c[i];sort(RALL(c));
  print(accumulate(ALL(c),0)-c[0]);
  ll v,w,cpos=0;
  while(deg1.size()) {
    v=deg1.front();deg1.pop();
    if(!deg1.size()) {ans[v]=c.back();break;}
    w=G[v][0];G[v].erase(G[v].begin());
    rep(i,G[w].size()) if(G[w][i]==v) G[w].erase(G[w].begin()+i);
    deg[w]--;
    if(deg[w]==1) deg1.push(w);
    ans[v]=c.back();c.erase(c.end()-1);
  }
  rep(i,n-1) cout<<ans[i]<<' ';print(ans[n-1]);
  return 0;
}