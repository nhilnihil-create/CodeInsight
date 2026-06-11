#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
struct Edge{
  int s;
  int t;
  int l;
};
struct Node{
  int no;
  int num;
  int c;
  vector<Edge> edge;
  void calc(int i){
    no=i;
    num=edge.size();
  }
};
bool cn(Node a,Node b){
  return a.num<b.num;
}
signed main(){
  int n;cin>>n;
  vector<Node> node(n+1);
  vector<int> c(n);
  rep(i,n-1){
    int a,b;
    Edge buf;cin>>a>>b;
    buf.s=a;buf.t=b;
    node[a].edge.push_back(buf);
    buf.s=b;buf.t=a;
    node[b].edge.push_back(buf);
  }
  rep(i,n)cin>>c[i];
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  /*rep(i,n){
    cout<<c[i]<<"\t";
  }
  cout<<endl;
  */
  int s=0;
  int max=0;int max_index=0;
  rep1(i,n){
    node[i].calc(i);
    if(node[i].num>max){
      max_index=i;
      max=node[i].num;
    }
  }
  queue<int> que;
  que.push(max_index);
  vector<bool> memo(n+1,true);
  node[max_index].c=c[0];
  memo[max_index]=false;
  s=1;
  int res=0;
  //cout<<"max_index = "<<max_index<<endl;;
  while(!que.empty()){
    int buf=que.front();
    que.pop();
    //memo[buf]=false;
    rep(i,node[buf].num){
      if(memo[node[buf].edge[i].t]){
        que.push(node[buf].edge[i].t);
        node[node[buf].edge[i].t].c=c[s];
        memo[node[buf].edge[i].t]=false;
        res+=c[s];
        //cout<<"res+= "<<c[s]<<endl;
        s++;
      }
    }
  }
  cout<<res<<endl;
  rep1(i,n){
    cout<<node[i].c<<endl;
  }
  return 0;
}