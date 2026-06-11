#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int N,M; vector<vector<int>> to,revto;
vector<bool> visited;
vector<int> stock,alt;
vector<int> vec; 

vector<int> par;

void dfs(int u){ //今この位置にいる // ここからdescentして行く
  if(visited[u]){ return;}
  
  visited[u] = true;
  
  for(auto v : to[u]){
    if(visited[v]){ continue;}
    
    
    dfs(v);
  }
  
  stock.push_back(u);
  
 
  return ;
}

int main(){ 
  
  cin >> N >> M;
 
  visited = vector<bool>(N,false);
  
  to.resize(N); revto.resize(N);
  
  for(int i = 0; i < N+M-1; i++){
    int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b); revto[b].push_back(a); //逆辺
  }
  
  for(int i = 0; i < N; i++){
    dfs(i);
  } // トポロジカルソート
  
  reverse(stock.begin(),stock.end());
 
  alt.resize(N);
  
  for(int i = 0; i < N; i++){
    alt[stock[i]] = i;
  }
  //OK
  
  
  vec.resize(N);
  
  for(int i = 0; i < N; i++){ //それぞれのノードについて、親を確定して行く
  
   int q = -1; int j;
    
    for(auto ne : revto[i]){
      int v = alt[ne]; //親の中で、最も数字がでかいものを選ぶ
      if( q < v){ q = v; j = ne;}
      
    }
    
    // pとqをつなぐ
      
   if( q == -1){ j = -1;}
    
    vec[i] = j;
  }
  
 
  for(auto ne : vec){
    cout << ne+1 << endl;
  }
  

  
  
  
 
  
  return 0;
}