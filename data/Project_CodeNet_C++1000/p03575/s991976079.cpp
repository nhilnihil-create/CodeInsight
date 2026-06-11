#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N,M;
  cin>>N>>M;
  int A[1000],B[1000];
  for(int i(0);i<M;i++){
    int a,b;
    cin>>a>>b;

    a--;
    b--;
    A[i] = a;
    B[i] = b;
  }
  int ans(0);
  for(int i(0);i<M;i++){
    vector<int> G[100];
    for(int j(0);j<M;j++){
      if(i != j){
        G[A[j]].push_back(B[j]);
        G[B[j]].push_back(A[j]);
      }
    }
    int cnt(0);
    int pathed[100] = {0};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int now = q.front();q.pop();
      for(int i(0);i<int(G[now].size());i++){
        int next = G[now][i];
        if(!pathed[next]){
          q.push(next);
          pathed[next] = 1;
          cnt++;
        }
      }
    }
    //cout << cnt << endl;
    if(cnt != N) ans++;
  }

  cout << ans << endl;
  return 0;
}


