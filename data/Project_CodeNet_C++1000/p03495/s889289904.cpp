#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n+1, 0);
  rep(i, n) {
    int t;
    cin >> t;
    v[t]++;
  }
  sort(v.begin(), v.end(), greater<int>());

  int c = 0;
  int sum = 0;
  rep(i, n+1) {
    if (c < k) { 
      sum += v[i];
      c++;
    }
  }
  cout << n - sum;
}
