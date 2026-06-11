#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   string s, ans;
   int K;
   cin >> s >> K;

   vector<vector<int>> alpha(26);

   rep(i, 0, s.length()) alpha.at((int)(s.at(i) - 'a')).push_back(i);

   bool done = false;
   map<string, int> exist;

   while (!done) {
     rep(i, 0, 26) {
       if (alpha.at(i).size() == 0) continue;
       else {
         vector<string> S;
         for (int j : alpha.at(i)) {
           S.push_back(s.substr(j, s.length() - j));
         }
         sort(S.begin(), S.end());
         for (string k : S) {
           rep(m, 1, k.length() + 1) {
             if (exist[k.substr(0, m)] != 0) continue;
             else {
               K--;
               if (K == 0) {
                 done = true;
                 ans = k.substr(0, m);
                 break;
               }
               exist[k.substr(0, m)]++;
             }
           }
           if (done) break;
         }
       }
       if (done) break;
     }
   }

   cout << ans << endl;
 }
