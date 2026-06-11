#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
   int n,m,x;
   cin >> n >> m >> x;
   vector<int> v(n+1,0);
   rep(i,m){
       int tmp;
       cin >> tmp;
       v[tmp]++;
   }
   int ans = 0,fans = 0;
   for (int i = x;i <= n;i++){
       ans +=v[i];
   }
   for (int j = x; j >= 0;j--){
       fans +=v[j];
   }
   fans = min(ans,fans);
   cout << fans << endl;
    return 0;
    
}