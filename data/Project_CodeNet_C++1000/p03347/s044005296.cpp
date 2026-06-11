#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N + 1, -1);
   for (int i = 0; i < N; ++i) cin >> A[i];
   auto __assert = [&](bool z) { if (!z) { cout << "-1\n"; exit(0); } };
   __assert(A[0] == 0);
   ll ans = 0;
   for (int i = 1; i <= N; ++i) {
      __assert(A[i] <= A[i - 1] + 1);
      if (A[i] <= A[i - 1]) ans += A[i - 1];
   }
   cout << ans << "\n";
   return 0;
}
