#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp(x,y) std::make_pair(x,y)
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
int N;
int a[200010],b[200010];
std::vector<int> edge[200010];
bool f[200010];
int temp;
void add_edge(int from,int to){
  edge[from].push_back(to);
  edge[to].push_back(from);  
}
int far_away(int s){
  fill(f,0);
  temp=0;
  int res;
  std::priority_queue<pi,std::vector<pi>,std::greater<pi> > q;  
  q.push(mp(0,s));
  while(!q.empty()){
    pi p=q.top();q.pop();
    int F=p.first,S=p.second;
    f[S]=true;
    int es=edge[S].size();
    rep(i,es){
      int e=edge[S][i];
      if(!f[e]){
	q.push(mp(F+1,e));
	if(temp<=F+1){
	  temp=F+1;
	  res=e;
	}
      }
    }
  }
  return res;
}
int diameter(){
  far_away(far_away(0));
  return temp+1;
}
void solve(){
  rep(i,N-1){
    add_edge(a[i],b[i]);
  }
  int L=diameter();
  //  prin(L);
  if(L%3==2) prin("Second");
  else prin("First");
}
int main(){
  cin>>N;
  rep(i,N-1){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  solve();
  return 0;
}
