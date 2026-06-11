#include <iostream>
#include <vector>
using namespace std;

int main(void){
   int n,m;
   cin >> n >> m;
   
   vector<int> k(n);
   vector<vector<int>> a(n,vector<int>(m));
   vector<int> t(m);
   for(int i = 0;i < n;i++){
       cin >> k[i];
       for(int j = 0;j < k[i];j++){
           cin >> a[i][j];
           a[i][j]--;
           t[a[i][j]]++;
       }
   }
   int ans = 0;
   for(int i = 0;i < m;i++){
       if(t[i] == n)ans++;
   }
   cout << ans << endl;
   
   
   
    return 0;
}
