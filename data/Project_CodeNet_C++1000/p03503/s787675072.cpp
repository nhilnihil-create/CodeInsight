#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n;
   cin >> n;
   vector<vector<int>> v(n,vector<int> (10));
   rep(i,n){
      rep(j,10){
         cin >> v[i][j];
      }
   }
   int ans = -1e9;
   vector<vector<int>> u(n,vector<int> (11));
   rep(i,n){
      rep(j,11){
         cin >> u[i][j];
      }
   }
   for (int bit = 1;bit < 1 << 10 ;bit++){
      vector<int> p(n,0);
      for (int j = 0; j < 10;j++){
         if (bit & 1 << j){
            for (int w = 0; w < n;w++){
               if (v[w][j] == 1) p[w]++;
            }
         }
      }
      int cnt = 0;

      for (int w = 0; w < n;w++){
            cnt+= u[w][p[w]];
      }
      ans = max(cnt,ans);
      //cout << bit << " " << cnt << endl; 
      
   }
   cout << ans << endl;
   
   

   return 0;
}
