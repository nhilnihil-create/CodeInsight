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

      long int arr[n];
      start = INT_MAX;

      for(int i = 0;i<n;i++){
       cin >> arr[i];
       start = min(start,arr[i]);
       }

       long int ans[m+1] = {0};

       for(int i = 0;i<start;i++)
        ans[i] = 0;

        for(int i = start;i<=m;i++)
        {
            for(int j = 0;j<n;j++)
            {
              if(arr[j] == i)
              {
                ans[i] = 1;
                break;
              }
              if(arr[j]<i)
              {
                  ans[i] = ans[i] || ans[i-arr[j]]^1;
              }
            }
        }
        
        if(ans[m])
         cout << "First" << '\n';
         else cout << "Second" << endl;


  } 
}


