#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int n,dist[101010];

int bfs(){
  deque<pint> dq;
  dq.push_back({1,1});
  dist[1]=1;
  while(dq.size()){
    pint p=dq.front();
    dq.pop_front();
    int now=p.first,d=p.second;
    if(dist[now]<d)continue;
    int next=(now+1)%n;
    if(dist[next]>d+1){
      dist[next]=d+1;
      dq.push_back({next,d+1});
      }
    next=(now*10)%n;
    if(dist[next]>d){
      dist[next]=d;
      dq.push_front({next,d});
      }
    }
  return dist[0];
  }      

int main(){
  cin>>n;
  rep(i,n)dist[i]=inf;
  cout<<bfs()<<endl;
  return 0;
  }
