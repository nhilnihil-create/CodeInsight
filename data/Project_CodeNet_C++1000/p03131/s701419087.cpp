#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  if (B-A<=2||K<A-1) cout << K+1 << endl;
  else {
    ll res = A;
    K -= A-1;
    if (K%2!=0) {
      res++;
      K--;
    }
    res += (B-A)*(K/2);
    cout << res << endl;
  }
}