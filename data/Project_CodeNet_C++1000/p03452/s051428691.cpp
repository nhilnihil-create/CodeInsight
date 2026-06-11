#include <bits/stdc++.h>


using namespace std;


struct edge{int to;int cost;};

vector<edge> tree[100010];

vector< int> d(100010 , -1e9);

bool f;
void bfs(int s){
  queue<int> q;
  q.push(s);
  d[s]=0;
  while(!q.empty()){
    
    int p=q.front();
    
    q.pop();
    for(auto x:tree[p]){
      
      int u=x.to,v=x.cost;
      
      if(d[u]==-1e9){
        d[u]=d[p]+v;
        q.push(u);
      }
      else{
        if(d[u]!=d[p]+v){
          f=false;
        }
      }
    }
  }
}

int main(){
  int n,m;
  
  cin >> n >> m;
  
  for(int i=0;i<m;i++){
    int l,r,d;
    
    cin >> l >> r >> d;
    l--,r--;
    
    tree[l].push_back({r,d});
    tree[r].push_back({l,-d});
  }
  
  f=true;
  for(int i=0;i<n;i++){
    if(d[i]!=-1e9){
      continue;
    }
    bfs(i);
    
    if(!f){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
