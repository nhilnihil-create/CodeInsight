#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     int N;
     string S;

     cin >> N >> S;

     vector<int> Esum(N, 0), Wsum(N, 0);

     rep(i, 0, N) {
       if (S.at(i) == 'E') {
         if (!i) Esum.at(i) = 1;
         else Esum.at(i) = Esum.at(i - 1) + 1;
       }
       else if (i) Esum.at(i) = Esum.at(i - 1);
     }

     rep(i, 0, N) {
       if (S.at(i) == 'W') {
         if (!i) Wsum.at(i) = 1;
         else Wsum.at(i) = Wsum.at(i - 1) + 1;
       }
       else if (i) Wsum.at(i) = Wsum.at(i - 1);
     }

     int ans = 300000;

     rep(i, 0, N) {
       if (!i) ans = min(ans, Esum.at(N - 1) - Esum.at(i));
       else if (i == N - 1) ans = min(ans, Wsum.at(N - 2));
       else ans = min(ans, Wsum.at(i - 1) + Esum.at(N - 1) - Esum.at(i));
     }
     cout << ans << endl;
 }
