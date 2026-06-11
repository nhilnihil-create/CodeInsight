#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   
   vector<int> vec(n);
   
   for (int i=0; i<n; i++) {
       cin >> vec.at(i); 
   }
   
   sort(vec.begin(), vec.end());
   
   int ans = 1;
   
   for (int i=n-1; i>0; i--) {
       if (vec.at(i) > vec.at(i-1)) ans++;
   }
   cout << ans << endl;
}