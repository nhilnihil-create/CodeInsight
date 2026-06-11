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
  priority_queue<pint,vector<pint>,greater<pint>> pq;
  pq.push({1,1});
  dist[1]=1;
  while(pq.size()){
    pint p=pq.top();
    pq.pop();
    int d=p.first,now=p.second;
    int next=(now+1)%n;
    if(dist[next]>d+1){
      dist[next]=d+1;
      pq.push({d+1,next});
      }
    next=(now*10)%n;
    if(dist[next]>d){
      dist[next]=d;
      pq.push({d,next});
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
