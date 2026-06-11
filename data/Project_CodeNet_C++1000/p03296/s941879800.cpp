#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N;

   cin >> N;

   vector<int> a(N);
   cin >> a.at(0);
   int ans = 0;
   for (int i = 1; i < N; i++) {
     cin >> a.at(i);
   }
   for (int i = 1; i < N; i++) {
     if (a.at(i) == a.at(i - 1)) {
       ans++;
       i++;
     }
   }

   cout << ans << endl;
}
