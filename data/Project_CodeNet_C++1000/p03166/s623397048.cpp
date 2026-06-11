#include <bits/stdc++.h>
using namespace std;

int main(){
  int V,E;
  cin>>V>>E;
  int dp[100100]={};
  
  //DAG　入力
  int t,s; 
  vector<vector<int>> G(V); 

  //ノードの入力次数を記録するテーブル
  int table[100010]={};

  for(int i=0;i<E;i++){
    cin>>s>>t;
    s--;
    t--;   
    G[s].push_back(t);
    table[t]++; 
  }
  
  //初期の入力のない辺をキューに挿入
  queue<int>Q;
  for(int i=0;i<V;i++){
    if(table[i]==0){
      Q.push(i);
    }
  }

  while(Q.size() != 0){
    int temp=Q.front();
    Q.pop();
    for(int i=0; i<G[temp].size(); i++){
      table[G[temp][i]]--;
      if(table[G[temp][i]]==0){
        Q.push(G[temp][i]);
        dp[G[temp][i]]=max(dp[G[temp][i]],dp[temp]+1);
      }
    }
  }
  int ans=0;
  for(int i=0;i<V;i++){
    ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
    
  return 0;
}
