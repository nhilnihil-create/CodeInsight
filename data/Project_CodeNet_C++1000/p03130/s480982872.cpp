#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[4];
int main() {
   for (int i=0; i<6; i++) {
       int t; cin >> t; a[t-1]++;
   } sort(a,a+4);
   //for (int x: a) cout << x;
   for (int i=0; i<4; i++) {
       if ((i==2 || i==3) && a[i]>=2) continue;
       if ((i==0 || i==1) && a[i]>=1) continue;
       cout << "NO"; return 0;
   }
   cout << "YES";
}