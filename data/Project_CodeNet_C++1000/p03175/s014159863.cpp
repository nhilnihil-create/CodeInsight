#include<bits/stdc++.h>
using namespace std;
long long int W[1000000];
long long int B[1000000];
void dfs(int a, int b,vector<int> V[], bool vis[])
{
  W[a] = 1;
  B[a] = 1;
  for(int i = 0;i<V[a].size();i++)
  {
    long long int c = V[a][i];
    if(vis[c] == false)
    {
      vis[c] = true;
      dfs(c,b,V,vis);
      W[a]  = (W[a]*(W[c]+B[c]))%1000000007;
      B[a] = (B[a]*(W[c]))%1000000007;
    }
  }
}
int main()
{
   int N;
   cin>>N;
   vector<int> V[N];
   bool vis[N];
   vis[0] = false;
   for(int i = 0 ;i<N-1;i++)
   {
     vis[i+1] = false;
     int a,b;
     cin>>a>>b;
     V[a-1].push_back(b-1);
     V[b-1].push_back(a-1);
   }
   vis[0] = true;
   dfs(0,0,V,vis);
   cout<<(W[0]+B[0])%1000000007;

}
