#include <bits/stdc++.h>
using namespace std;

vector<long> a;
long N,M;
vector<vector<int>> g(100005);
vector<int> d(100005,-1);
vector<int> p(100005);
int c=0;
void bfs(int s){
  queue<long> q;
  d[s] = c;
  q.push(s);
  long u;
  while (!q.empty()) {
        int v = q.front(); // キューから先頭頂点を取り出す
        q.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : g[v]) {
            if (d[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            d[nv] = c;
            q.push(nv);
        }
    }

return;

}

int main() {
cin>>N>>M;
for(int i=0;i<N;i++) cin>>p[i],p[i]--;
for(int i=0;i<M;i++){
  int a,b;
  cin>>a>>b;
  a--,b--;
  g[a].push_back(b);
  g[b].push_back(a);
}


  for(int i=0;i<N;i++){
    if(d[i]==-1){
      d[i]=c;
      bfs(i);
      c++;
    }
  }

long ans=0;
for(int i=0;i<N;i++){
  if(d[i]==d[p[i]]||p[i]==i) ans++;
}
cout<<ans<<endl;


}
