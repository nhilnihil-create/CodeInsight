#include<iostream>
#include<algorithm>
#include<climits>
#include<utility>
#include<vector>
#include<deque>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int NMAX=1<<17;
int k;
vector<pi> edge[100010];
int d[100010];
int o1_bfs(){
  rep(i,k){
    d[i]=INT_MAX;
  }
  deque<int> deq;
  deq.push_back(1);
  d[1]=1;
  while(deq.size()){
    int a=deq.front();deq.pop_front();
    if(a==0) break;
    rep(i,edge[a].size()){
      int pf=edge[a][i].first,ps=edge[a][i].second;
      if(ps+d[a]<d[pf]){
	if(ps==0){
	  deq.push_front(pf);
	  d[pf]=d[a];
	}
	else{
	  deq.push_back(pf);
	  d[pf]=d[a]+1;
	}
      }
    }
  }
  return d[0];
}
  
int main(){
  scan(k);
  rep(i,k){
    edge[i].push_back(pi((i*10)%k,0));
  }
  rep(i,k-1){
    edge[i].push_back(pi(i+1,1));
  }
  edge[k-1].push_back(pi(0,1));
  prin(o1_bfs());
  //  rep(i,k)prin(d[i]);
  
  
  return 0;
}
