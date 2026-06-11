#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 bool isPrime(int n) {
   for (int i = 2; i * i <= n; i++) {
     if (n % i == 0) return false;
   }
   return true;
 }

 int main() {
   int N; cin >> N;
   vector<int> ans;

   rep(i, 6, 55556) {
     if (isPrime(i) && i % 5 == 1) ans.push_back(i);
     if (ans.size() == N) break;
   }

   rep(i, 0, N - 1) cout << ans.at(i) << " ";
   cout << ans.back() << endl; 
 }
