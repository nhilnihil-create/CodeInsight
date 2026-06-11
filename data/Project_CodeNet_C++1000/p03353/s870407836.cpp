#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
   string s, ans;
   int K;
   cin >> s >> K;
   vector<string> sub;
   rep(i, 1, 6) {
     rep(j, 0, s.length() + 1 - i) {
       sub.push_back(s.substr(j, i));
     }
   }
   sort(sub.begin(), sub.end());
   sub.erase(unique(sub.begin(), sub.end()), sub.end());
   cout << sub.at(K - 1) << endl;
 }
