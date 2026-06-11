#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i++)
#define RFOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i--)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using ll = long long;

struct node{
  int c, v, a, b;
  vector<node*> suc;
};

int main(){
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<node> g(n);
  vector<bool> use(n, true);

  REP(i, n){
    g[i].c = s[i] == 'A';
    g[i].v = i;
  }

  REP(i, m){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].suc.emplace_back(&g[b]);
    g[b].suc.emplace_back(&g[a]);
  }

  //既に満たしていない点をチェック
  stack<int> q;
  REP(i, n){
    REP(j, g[i].suc.size()){
      if(g[i].suc[j]->c) g[i].a++;
      else g[i].b++;
    }
    if(g[i].a==0 || g[i].b==0){
      q.push(i);
      use[i] = false;
    }
  }
  
  //条件を満たしていない点を取り除いて行く
  int cnt = 0;
  while(!q.empty()){
    int v = q.top(); q.pop();
    cnt++;
    REP(i, g[v].suc.size()){
      node* next = g[v].suc[i];
      if(v == next->v) continue;

      if(g[v].c == 1) next->a--;
      else next->b--;

      if(next->a == 0 || next->b == 0){
        if(use[next->v]){
          use[next->v] = false;
          q.push(next->v);
        }
      }
    }
  }

  if(cnt == n) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}

