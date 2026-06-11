#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 解説AC

int main(){ 
  
  int N; cin >> N;
  
  vector<vector<int>> to(N);
  
  for(int i = 0; i < N-1; i++){ 
    int a,b; cin >> a >> b; 
    a--; b--;
    
    to[a].push_back(b);
    to[b].push_back(a);
    
  }

  // 0を頂点としてもっとも遠い点を探す
  
  vector<int> dist(N,-1);
  dist[0] = 0;
  
  queue<int> Q; Q.push(0);
  
  while(!Q.empty()){ 
    int p = Q.front(); Q.pop();
    
    for(int i = 0; i < (int)to[p].size(); i++){ 
      
      int q = to[p][i];
      
      if( dist[q] != -1 ){ continue;}
      else{ dist[q] = dist[p]+1; Q.push(q);}
      
    }
   
    
  }
  
  int u = 0; int res = 0;
  
  for(int i = 0; i < N; i++){ 
    
    if( dist[i] > res ){ res = dist[i]; u = i;}
    
  }
  
  vector<int> dist2(N,-1); dist2[u] = 0;
  
  queue<int> Q2; Q2.push(u);
  
  while(!Q2.empty()){
    
    int p = Q2.front(); Q2.pop();
    
    for(int i = 0; i < (int)to[p].size(); i++){
      
      int q = to[p][i];
      
      if( dist2[q] != -1){ continue;}
      else{
        dist2[q] = dist2[p]+1; 
        Q2.push(q);
        
      }
    }
  }
  
  res = 0; int v = 0;

  for(int i = 0; i < N; i++){ 
    
    if( dist2[i] > res ){ v = i; res = dist2[i];}
    
  }

  // uとvの距離はres;
  
  if( res % 3 == 1 ){ cout << "Second" << endl;}
  else{ cout << "First" << endl;}
  
  return 0;
} 
    
    
    
  