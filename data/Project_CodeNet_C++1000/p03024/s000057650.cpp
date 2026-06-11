#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   string S;

   cin >> S;

   int k = S.length();
   int count = 0;

   for (int i = 0; i < k; i++) {
     if (S.at(i) == 'o') count++;
   }

   if (count + 15 - k >= 8) cout << "YES" << endl;
   else cout << "NO" << endl;
 }
