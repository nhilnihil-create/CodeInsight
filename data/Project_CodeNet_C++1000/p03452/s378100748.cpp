#include<bits/stdc++.h>
using namespace std;

const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

long long D[101010];

vector<pair<int, int> > conn[101010];

void dfs(int a, int d)
{
  if(D[a] == INFLL)
  {
    D[a] = d;
    for(auto x: conn[a])
    {
      int u, v; tie(u, v) = x;
      dfs(u, d+v);
    }
  }
  if(D[a] != d) { puts("No"); exit(0);}
}


int N, M;
int main()
{
  scanf("%d%d", &N, &M);  
  for(int i=0; i<M; ++i)
  {
    int l, r, d; scanf("%d%d%d", &l, &r, &d);
    conn[l].emplace_back(r, d);
    conn[r].emplace_back(l, -d);
  }
  memset(D, 0x3f, sizeof D);
  for(int i=1; i<=N; ++i)
  {
    if(D[i] == INFLL) dfs(i, 0);
  }
  puts("Yes");
}