#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,C; cin >> N >> C;
  vector<priority_queue<int,vector<int>,greater<int>>> q(C);
  
  for(int i=0; i<N; i++){
    int s,t,c; cin >> s >> t >> c;
    c--;
    q[c].push(s);
    q[c].push(t);
  }
  
  vector<queue<pair<int,int>>> cont(C);
  for(int i=0; i<C; i++){
    int s=0,t=0;
    while(!q[i].empty()){
      int ss=q[i].top(); q[i].pop();
      int tt=q[i].top(); q[i].pop();
      if(t==ss){
        t=tt;
        if(q[i].empty()) cont[i].push(make_pair(s-1,t));
      }else{
        if(s!=0) cont[i].push(make_pair(s-1,t));
        s=ss;
        t=tt;
        if(q[i].empty()) cont[i].push(make_pair(s-1,t));
      }
    }
  }
  
  int time[100010]={};
  for(int i=0; i<C; i++){
    while(!cont[i].empty()){
      pair<int,int> qq=cont[i].front();
      cont[i].pop();
      time[qq.first]++;
      time[qq.second]--;
    }
  }
  for(int i=0; i<100009; i++){
    time[i+1]+=time[i];
  }
  int result=0;
  for(int i=0; i<100010; i++){
    result=max(result,time[i]);
  }
  cout << result << endl;
}