#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define mod (1000000007)
 
// vector<long long int> temp(40002);//long int vis[1000002] = {0};
  // vector<long int> g[1000002];

int main() {
 
  long long int t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
 //cin >> t;
  while(t--){
 
    int n,m,x = 0,y = 0,start = 0,end = 0,index = 0,z;

    string a,b;
    cin >> a >> b;

    n = a.size();
    m = b.size();

    int arr[n+1][m+1];
    for(int i = 0;i<=n;i++)
    {
      for(int j = 0;j<=m;j++)
      {
          if(i == 0 || j == 0)
           arr[i][j] = 0;
          
          else if(a[i-1] == b[j-1])
           {
             arr[i][j] = arr[i-1][j-1]+1;
           }
           else
           {
             arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
           }
           
      }
    }
    string ans = "";
    int i = n,j = m;

    while(i>0 && j>0)
    {
      if(a[i-1] == b[j-1])
      {
        ans+=a[i-1];
        i--;j--;
        continue;
      }
      if(arr[i-1][j] > arr[i][j-1])
       i--;
       else
       {
         j--;
       }
       

    }


    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
      
  } 
}
