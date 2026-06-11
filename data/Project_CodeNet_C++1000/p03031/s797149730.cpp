#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
   int n,m;
   cin >> n >> m;
   vector<vector<int>>v(m);
   for(int i = 0; i < m; i++)
   {
       int k;
       cin >> k;
       v[i].resize(k);
       for(int j = 0; j < k; j++)
       {
           cin >> v[i][j];
           v[i][j]--;
       }
       sort(v[i].begin(),v[i].end());
   }
   vector<int>p(m);
   for(int i = 0; i < m; i++) cin >> p[i];
   int answer = 0;
   for(int bit=0;bit<(1<<n);bit++)
   {
       vector<int>sum(m,0);
       for(int i=0;i<n;i++)
       {
           if(bit&(1<<i))
           {
               for(int j = 0; j < m; j++)
               {
                   if(binary_search(v[j].begin(),v[j].end(),i)) sum[j]++;
               }
           }
       }
       bool f = true;
       for(int i = 0; i < m; i++) if(sum[i]%2 != p[i]) f = false;
       if(f) answer++;
   }
   cout << answer << endl;
}
