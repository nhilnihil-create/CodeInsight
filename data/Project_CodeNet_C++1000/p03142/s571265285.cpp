#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,M;

vector<vector<int>> to;
vector<bool> visited;

vector<int> res;

void dfs(int v){
 if( visited[v]){ return ;}
 
 visited[v] = true;
 
  for(auto ne : to[v]){
   dfs(ne);
  }
   
   res.push_back(v);
   
}
   


int main(){
 cin >> N >> M;
 vector<int> numbering(N,0);
 to.resize(N); visited = vector<bool>(N,false);
 for(int i = 0; i < N-1+M; i++){
 int a,b; cin >> a >> b; a--; b--;
 to[b].push_back(a); //子から親に辺をはる
 }
 
 for(int i = 0; i < N; i++){ 
 dfs(i);
 } //トポロジカルソート
 
 for(int i = 0; i < N; i++){
  numbering[res[i]] = i+1;
  }
  
 
  for(int i = 0; i < N; i++){ 
  //全ての親の中で数字が最も大きいものを採用
   int cnt = -1;
   int ans = 0;
   for(auto ne : to[i]){
     
     if( numbering[ne] > cnt ){ cnt = numbering[ne]; ans = ne+1; }
     
   }
   
   
   cout << ans << endl;
   
  }
   
   return 0;
}
   