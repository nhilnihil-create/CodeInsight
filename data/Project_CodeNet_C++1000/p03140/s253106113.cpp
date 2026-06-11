#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N, ans = 0;
   string A, B, C;
   cin >> N >> A >> B >> C;

   for (int i = 0; i < N; i++) {
     if (A.at(i) != B.at(i) && B.at(i) != C.at(i) && C.at(i) != A.at(i)) ans += 2;
     else if (A.at(i) != B.at(i) || B.at(i) != C.at(i) || C.at(i) != A.at(i)) ans++;
   }

   cout << ans << endl;
  }
