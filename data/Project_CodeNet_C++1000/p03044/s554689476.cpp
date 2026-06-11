#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n;
  cin >> n;
  int u[n],v[n],w[n],flag[n];
  vector<vector<int>> vec(n),wei(n);
  rep(i,n-1){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
    vec[u[i]].push_back(v[i]);
    vec[v[i]].push_back(u[i]);
    wei[u[i]].push_back(w[i]);
    wei[v[i]].push_back(w[i]);
    flag[i] = -1;
  }
  flag[n-1] = -1;
  queue<int> que;
  que.push(0);
  flag[0] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();
    rep(i,int(vec[now].size())){
      if(flag[vec[now][i]]==-1){
        que.push(vec[now][i]);
        flag[vec[now][i]] = (wei[now][i]%2 ? !flag[now]:flag[now]);
      }
    }
  }
  rep(i,n)cout << flag[i] << endl;
  return 0;
}