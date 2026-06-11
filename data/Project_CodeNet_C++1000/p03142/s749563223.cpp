#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

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
  int in_num;
  vector<Node*> child;
  void build(int i){
    no=i;par=i;in_num=0;
  }
};
signed main(){
  int n,m;cin>>n>>m;
  vector<Node> node(n+1);
  rep(i,n+1){
      node[i].build(i);
  }
  rep(i,n+m-1){
      int a,b;cin>>a>>b;
      node[a].child.push_back(&node[b]);
      node[b].in_num++;
  }
  vector<int> res(n+1,0);
  int root=0;
  rep1(i,n){
      if(node[i].in_num==0){
          root=i;
          break;
      }
  }
  queue<Node*> que;
  que.push(&node[root]);
  while(!que.empty()){
      Node* buf=que.front();que.pop();
      int num=buf->child.size();
      rep(i,num){
          buf->child[i]->in_num-=1;
          if(buf->child[i]->in_num==0){
              node[buf->child[i]->no].par=buf->no;
              res[buf->child[i]->no]=buf->no;
              que.push(buf->child[i]);
          }
      }
  }
  rep1(i,n){
      cout<<res[i]<<"\n";
  }
  return 0;
}