#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i=0; i<(int)n; i++)
using vb = vector<bool>;

int main(){
  int N,M;
  cin>>N>>M;
  vvi G(N);
  int x,y,z;
  rep(i,M){
    cin>>x>>y>>z;
    x--;y--;
    G[x].pb(y);
    G[y].pb(x);
  }

  int renketu = 0;
  vb checked(N, false);
  for(int i=0; i<N; i++){
    if(checked[i])continue;
    queue<int> que;
    que.push(i);

    while(!que.empty()){
      int now = que.front();
      que.pop();

      if(!checked[now]){
        checked[now] = true;
        for(int next: G[now]){
          que.push(next);
        }
      }
    }
    renketu++;
  }

  cout<<renketu<<endl;
}