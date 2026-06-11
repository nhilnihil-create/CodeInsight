#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, a[3005], sum;
int main() {
   cin >> n;
   for (int i=0; i<n; i++) {
       cin >> a[i]; sum+=a[i];
   }
   
   cout << sum-n;
   
}