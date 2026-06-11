#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mod (1000000007)
 
long int vis[100002] = {0};
   vector<long int> g[100002];


void dfs(int u,long int x,long int &value)
{
  // vis[u] = 1;

    value = max(value,x);
   for(auto v : g[u])
   {
      if(vis[v] == 0){
        x++;
       dfs(v,x,value);
      }
        x = 0;
   }
}
int main() {
 
  long long int t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
 //cin >> t;
  while(t--){
 
   long int n,m,x = 0,y = 0,start = 0,end = 0,index = 0,z;

      cin >> n >> m;

      long long int arr[n][m];

      char ch[n][m];

      for(int i = 0;i<n;i++)
       for(int j = 0;j<m;j++)
        cin >> ch[i][j];

        start = 1;
        for(int i = 1;i<m;i++)
        {
          if(start && ch[0][i] != '#')
              arr[0][i] = 1;
          else{
            start = 0;
            arr[0][i] = 0;
          } 

        }
        start = 1;
        for(int i = 1;i<n;i++)
        {
          if(start && ch[i][0] != '#')
              arr[i][0] = 1;
          else{
            start = 0;
            arr[i][0] = 0;
          } 
        }

      arr[0][0] = 0;

      for(int i = 1;i<n;i++)
      {
        for(int j = 1;j<m;j++)
        {
          if(ch[i][j] == '#')
             arr[i][j] = 0;
             else
            arr[i][j] = (arr[i-1][j]%mod + arr[i][j-1]%mod)%mod;
        }
      }
         
      cout << arr[n-1][m-1];
  } 
}
