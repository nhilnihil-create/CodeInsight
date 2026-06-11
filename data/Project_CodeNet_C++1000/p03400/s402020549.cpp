#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   int n,d,x;
   cin >> n;
   cin >> d >> x;
   vector<int> a(n);
   int ans = 0;
   for(int i = 0;i < n;i++){
       cin >> a[i];
       ans += (d + a[i] - 1) / a[i];
   }
   ans += x;
   cout << ans << endl;
   
   
}
