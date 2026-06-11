#include <bits/stdc++.h>
using namespace std;
int main(){
   int n,t;
   cin >> n >> t;
   int ans = 1e9;
   for(int i=0;i<n;i++){
      int c,T;
      cin >> c >> T;
      
      if(c < ans && T <=t){
         ans = c;

      }
   }
   if(ans == 1e9){
      cout << "TLE" <<endl;

   }
   else cout << ans  << endl;
}