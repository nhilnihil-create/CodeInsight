#include<bits/stdc++.h>
using namespace std;
int main()
{
  int K; scanf("%d", &K);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  vector<bool> vis(K+1);
  Q.emplace(0, 1);
  while(!Q.empty())
  {
    int dist, node; tie(dist, node) = Q.top(); Q.pop();
    if(vis[node]) continue; vis[node] = true;
    if(node == 0)
    {
        printf("%d\n", dist+1);
        return 0;
    }
    Q.emplace(dist, node*10%K);
    Q.emplace(dist+1, (node+1)%K);
  }
}