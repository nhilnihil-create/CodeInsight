#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


signed main(){
  cin.tie(0);	
  //ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<PII> x[n];
  rep(i,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    x[u].push_back(make_pair(v,w));
    x[v].push_back(make_pair(u,w));
  }
  int visited[n]={};
  visited[0]=1;
  queue<int> bfs;
  bfs.push(0);
  while(!bfs.empty() ){
    int num=bfs.front();
    // cout<<num<<endl;
    bfs.pop();
    rep(i,x[num].size() ){
      if(visited[x[num][i].F]==0){
	if(x[num][i].S % 2 == 0){
	  visited[x[num][i].F]=visited[num];
	}else{
	  visited[x[num][i].F]=(visited[num])*(-1);
	}
	bfs.push(x[num][i].F);
      }
    }
  }
  rep(i,n){
    if(visited[i]==-1) cout<<0<<endl;
    else cout<<1<<endl;
  }
  
  return 0;
}
