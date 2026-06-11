#include<bits/stdc++.h>
using namespace std;
int N; long long D[101010];
int size[101010], parent[101010];
map<long long, int> D2I; //Distance-index;
vector<int> child[101010];
void check(bool p)
{
  if(!p)
  {
    puts("-1");
    exit(0);
  }
}
long long dfs(int ind, int height)
{
  long long ans = height;
  for(auto x: child[ind]) ans += dfs(x, height+1);
  return ans;
}
void verify_print()
{
  int root = 0;
  for(int i=1; i<=N; ++i)
  {
    if(parent[i]) child[parent[i]].push_back(i);
    else root = i;
  }
  check(dfs(root, 0) == D[root]);
  for(int i=1; i<=N; ++i)
    if(parent[i])
      printf("%d %d\n", parent[i], i);
  return;
}
int main()
{
  vector<pair<long long, int> > V;
  scanf("%d", &N);
  for(int i=1; i<=N; ++i)
  {
    scanf("%lld", D+i);
    V.emplace_back(D[i], i);
    D2I[D[i]] = i;
  }
  sort(V.rbegin(), V.rend());
  for(auto x: V)
  {
    long long distance; int index; tie(distance, index) = x;
    size[index]++;
    
    if(V[V.size()-1] == x) check(size[index] == N);
    else
    {
      check(size[index] <= (N-1)/2);
      long long pdist = distance - (N-2*size[index]);
      int pind = D2I[pdist]; check(pind != 0);
      parent[index] = pind; size[pind] += size[index];
    }
  }  
  verify_print();
  return 0;
}