#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
struct Node{
  int no;
  int par;
  int num;
  void build(int i){
    no=i;
    par=i;
    num=inf;
  }
  vector<Node*> child;
};
signed main(){
  int n;cin>>n;
  vector<Node> node(n+1);
  rep1(i,n){
    node[i].build(i);
  }
  rep(i,n-1){
    int a,b;cin>>a>>b;
    node[a].child.push_back(&node[b]);
    node[b].child.push_back(&node[a]);
  }
  vector<int> c(n);
  rep(i,n)cin>>c[i];
  sort(c.begin(),c.end());
  queue<Node> que;
  node[1].num=c[n-1];
  que.push(node[1]);
  int cur=n-2;
  while(!que.empty()){
    Node buf=que.front();
    que.pop();
    int k=buf.child.size();
    rep(i,k){
      if(buf.par!=buf.child[i]->no){
        buf.child[i]->par=buf.no;
        buf.child[i]->num=c[cur];
        cur--;
        que.push(*buf.child[i]);
      }
    }
  }
  int sum=0;
  rep(i,n-1){
    sum+=c[i];
  }
  cout<<sum<<"\n";
  rep1(i,n){
    printf("%lld ",node[i].num);
  }
  cout<<endl;
  return 0;
}
