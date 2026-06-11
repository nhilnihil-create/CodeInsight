#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, diff;
map<int, int> ca;
int main() {
   cin >> n;
   for (int i=0; i<n; i++) {
       int x; cin >> x;
       ca[x]++;
   }
   
   cin >> m;
   while (m--) {
       cin >> diff;
       if (ca[diff]) {
           ca[diff]--;
       } else {
           cout << "NO"; return 0;
       }
   }
   cout << "YES";
}