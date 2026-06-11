#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
 ll N,M; cin >> N >> M;
  vector<vector<int>> to(N);
  for(ll i = 0; i < M; i++){
    ll a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b); to[b].push_back(a);
  }
  
  bool flag = false; //奇数ループが存在するか否か
  
  //閉路検索はBFSで可能
  vector<ll> visited(N,-1);//-1は未到達
  vector<bool> color(N,true); //trueは白
  ll black = 0; ll white = 0; //偶数を黒、奇数を白
  
  queue<ll> Q; Q.push(0); visited[0] = 0;
  
  while( !Q.empty()){
    ll p = Q.front(); Q.pop();
    for(auto q : to[p]){
      if( visited[q] == -1){ //　未到達なら進める
        color[q] = !color[p];
        visited[q] = visited[p]+1;
        Q.push(q);
      }
      else if( abs(visited[q]-visited[p]) == 1){ //直前におとづれていた時
        continue;}
      else{ //ループ検出
        if( (visited[p]+visited[q])% 2 == 0){ //奇数ループ発見
          flag = true; break;
        }
      }
    }
    if(flag){ break;}
  }
        
  for(auto ne : color){
    if(ne){ white++;} else{ black++;}
  }
  
  if(flag){
    cout << (N*(N-1))/2-M << endl;
  }
  else{
    cout << black*white-M << endl;
  }
  
  return 0;
}
  
  