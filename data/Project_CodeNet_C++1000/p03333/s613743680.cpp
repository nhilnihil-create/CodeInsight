#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main() {
   int N;
   cin >> N;
   int l, r;
   vector<int> L, R;
   for (int i = 0; i < N; i++) {
      cin >> l >> r;
      L.push_back(l);
      R.push_back(r);
   }
   L.push_back(0);
   R.push_back(0);
   sort(L.begin(), L.end());
   sort(R.begin(), R.end());
   ll ans = 0;
   for (int i = 0; i <= N; i++) {
      ans += max(0, 2 * (L[N - i] - R[i]));
   }
   cout << ans << endl;
   return 0;
}
