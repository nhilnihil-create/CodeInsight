#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int w;
   string S;

   cin >> S >> w;

   for (int i = 0; i < S.length(); i += w) {
     cout << S.at(i);
   }
   cout << endl;
  }
