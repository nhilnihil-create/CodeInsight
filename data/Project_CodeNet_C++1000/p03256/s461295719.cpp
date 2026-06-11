#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll N,M;
string s;
vector<ll> g[200010];
ll cnt[200010][2];
bool vis[200010];

int main(){
  cin>>N>>M;
  cin>>s;
  rep(i,M){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i,N){
    for(ll nv : g[i])cnt[i][s[nv]-'A']++;
  }

  queue<int> que;
  rep(i,N){
    if(cnt[i][0]==0||cnt[i][1]==0){
      vis[i]=true;
      que.push(i);
    }
  }
  while(que.size()){
    int v=que.front(); que.pop();
    int c=s[v]-'A';
    for(int nv : g[v]){
      if(vis[nv])continue;
      cnt[nv][c]--;
      if(cnt[nv][c]==0){
        que.push(nv);
        vis[nv]=true;
      }
    }
  }

  rep(i,N){
    if(!vis[i]){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;

  return 0;
}
