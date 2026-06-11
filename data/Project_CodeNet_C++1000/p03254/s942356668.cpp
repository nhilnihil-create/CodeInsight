#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   long n,x;
   cin >> n >> x;
   vector<long> a(n);
   for(int i = 0;i < n;i++){
       cin >> a[i];
   }
   sort(a.begin(),a.end());
   int ans = 0;;
   for(int i = 0;i < n - 1;i++){
       if(x >= a[i]){
           x -= a[i];
           ans++;
       }else{
           break;
       }
   }
   if(x == a[n - 1])ans++;
   cout << ans << endl;
}
