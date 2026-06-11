#include <bits/stdc++.h>

 using namespace std;

 int main() {
   int N, K;
   cin >> N >> K;

   if (N % 2 == 0) {
     if (K <= N / 2) cout << "YES" << endl;
     else cout << "NO" << endl;
   }

   else {
     if (K <= (N + 1) / 2) cout << "YES" << endl;
     else cout << "NO" << endl;
   }
 }
