#include <bits/stdc++.h>
using namespace std;
int main(){
   long long n, a[100100], b[100100], i, ans=0, sumprepare=0, dif[100100], shortage=0;
   cin >> n;
   for(i=0;i<n;i++){
       cin >> a[i];
   }
   for(i=0;i<n;i++){
       cin >> b[i];
       sumprepare+=a[i]-b[i];
       dif[i]=a[i]-b[i];
       if(a[i]<b[i]){
           ans++;
           shortage+=a[i]-b[i];
       }
   }
   if(sumprepare<0) {
       cout << -1 <<endl;
       return 0;
   }
   sort(dif, dif+n, greater<long long>());
   i=0;
   while(1){
       if(shortage>=0) break;
       shortage+=dif[i];
       i++;
       ans++;
   }
   cout <<ans <<endl;
   return 0;
}