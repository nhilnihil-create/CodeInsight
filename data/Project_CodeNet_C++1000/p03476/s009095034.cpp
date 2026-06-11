#include <bits/stdc++.h>
using namespace std;


int main() {
   int  Q;
   cin >> Q;
   int a[100001];
   a[1]=0;
   bool b;
   for (int i=1; i<100001; i++) {
       b=false;
       if (i==1) continue;
       if (i%2==0) {
           a[i]=a[i-1];continue;
       }
       for (int j=2; j<=sqrt(i); j++) {
           if (i%j==0) {
               a[i]=a[i-1];b=true;break;
           }
       }
       if (b) continue;
       for (int j=2; j<=sqrt((i+1)/2); j++) {
           if (((i+1)/2)%j==0) {
               a[i]=a[i-1]; b=true;break;
           }
       }
       if (b) continue;
       a[i]=a[i-1]+1;
   }
   for (int i=0; i<Q; i++) {
       int l,r;
       cin >> l >> r;
       cout << a[r]-a[l-1] << endl;
   }
}