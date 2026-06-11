// A

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
int N,c[100000];
vector<int> G[100001];
int ans[100001] = {0};
int pathed_dfs[100001] = {0};
ll sum(0);

void dfs(int now){
  pathed_dfs[now]++;
  for (int i(0);i<G[now].size();i++){
    int next = G[now][i];
    if (pathed_dfs[next] == 0){
      sum += min(ans[now],ans[next]);
      dfs(next);
    }
  }
}

int main(){
  cin>>N;
  for (int i(0);i<N-1;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i(0);i<N;i++) cin>>c[i];
  sort(c,c+N,greater<int>());
  queue<int> q;
  int pathed[100001] = {0};
  q.push(1);
  int cnt(0);
  while(!q.empty()){
    int now = q.front();q.pop();
    ans[now] = c[cnt];
    cnt++;
    pathed[now] = 1;
    for (int i(0);i<G[now].size();i++){
      int next = G[now][i];
      if (pathed[next] == 0){
        q.push(next);
      }
    }
  }
  dfs(1);
  cout << sum << endl;
  for (int i(1);i<=N;i++) cout << ans[i] << " ";
  return 0;
}
