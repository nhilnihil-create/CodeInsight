#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int main() {
   vector<char> a(6),b(6);
   for(int i=0;i<6;i++){
       cin >> a[i];
   }
   string ans="YES";
   for(int i=0;i<6;i++){
       if(a[i]!=a[5-i]) {
           ans = "NO";
           break;
       }
   }
   cout << ans << endl;
}
