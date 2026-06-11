#include<bits/stdc++.h>
using namespace std;

int main(){  
  int N;
  cin>>N;
  vector<vector<int>> G(N);
  vector<pair<int,int>> vp;

  for(int i=1;i<N;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    vp.emplace_back(a,b);
  }
  int C[10010];
  int sum=0;
  for(int i=0;i<N;i++){
    cin>>C[i];
  }
  
  //最大スコア計算
  sort(C,C+N);
  for(int i=0;i<N-1;i++){
    sum+=C[i];
  }
  cout<<sum<<endl;
  
  //構築
  queue<int>que;
  que.push(0);  
  vector<int>ans(N,0);
  int k=N-1;
  //cout<<"#k"<<k<<" "<<C[k]<<endl;
  int l;
  int qq;
  
  //cout<<"G[0].size()"<<G[0].size()<<endl;
  //cout<<"que.size()"<<que.size()<<endl;
  
  while(que.size()!=0){
    
    qq=que.front();
    //cout<<"#"<<qq<<endl;
    que.pop();
    ans[qq]=C[k];
    
    k--;
    
    l=G[qq].size();
    //cout<<"$2$"<<l<<endl;
    for(int i=0;i<l;i++){
      if(ans[G[qq][i]]==0){
        que.push(G[qq][i]);
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}


