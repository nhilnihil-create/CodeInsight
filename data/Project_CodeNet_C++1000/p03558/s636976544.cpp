#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

ll k;
const int V=100000;
using P=pair<int,int>;
vector<P> G[V];
int dist[V];
bool used[V];
void dijkstra(){
  fill_n(dist,V,INF);
  fill_n(used,V,false);
  priority_queue<P,vector<P>,greater<P>> q;
  q.push(P(1,1));
  while(!q.empty()){
    int d; int t;
    tie(d,t)=q.top();q.pop();
    if(used[t])continue;
    used[t]=true;dist[t]=d;
    int next=t*10;
    next%=k;
    int value=d;
    if(dist[next]<=value){
      //pass
    }else{
      q.push(P(value,next));
    }
    FOR(i,1,10){
      next=t+i;
      next%=k;
      value=d+i;
      if(dist[next]<=value)continue;
      q.push(P(value,next));
    }
  }
}

int main(){
  cin>>k;
  dijkstra();
  cout<<dist[0]<<endl;
  return 0;
}