#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
using namespace std;

#define N 200002

vector<int >edge[N];

char s[N];
int vis[N][4];
char t[4] ={'A','A','B','B'};
bool dfs(int node,int ord) {
  if(vis[node][ord]==1) {
    return true;
  }
  vis[node][ord] = 1;
  char tt = t[(ord+1)%4];
  for(int i=0;i<edge[node].size();++i) {
    int ch = edge[node][i];
    char g = s[ch];
    if(tt==g) {
      if(dfs(ch,(ord+1)%4)) {
        return true;
      }
    }
  }
  vis[node][ord] = 2;
  return false;
}
void solve() {
  int n,m;scanf("%d %d",&n,&m);
  scanf(" %s",s+1);
  for(int i=m;i;--i) {
    int a,b;scanf("%d %d",&a,&b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i=1;i<=n;++i) {
    if(!vis[i][0] && s[i]=='A') {
      if(dfs(i,0)) {
        printf("Yes\n" );
        return;
      }
    }
  }
  printf("No\n");
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
