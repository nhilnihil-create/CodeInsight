#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector< vector < pair<int,int> > > Graph(N);
  for(int i=0;i<N-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    Graph[u].push_back(make_pair(v,w));
    Graph[v].push_back(make_pair(u,w));
  }
  stack<int> stack;
  stack.push(0);
  vector<int> color(N,-1);
  color[0]=0;
  while(!stack.empty()){
    int state=stack.top();
    stack.pop();
    for(pair<int,int> p:Graph[state]){
      if(color[p.first]==0 || color[p.first]==1){
        continue;
      }
      if(p.second%2==0){
        color[p.first]=color[state];
        stack.push(p.first);
      }
      if(p.second%2==1){
        color[p.first]=1-color[state];
        stack.push(p.first);
      }
    }
  }
  for(int i=0;i<N;i++){
    cout << color[i] << endl;
  }
}