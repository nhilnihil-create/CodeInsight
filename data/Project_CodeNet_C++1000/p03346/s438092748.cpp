#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> dp(N + 1);
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      dp[x] = dp[x - 1] + 1;
   }
   cout << N - *max_element(dp.begin(), dp.end()) << "\n";
   return 0;
}
