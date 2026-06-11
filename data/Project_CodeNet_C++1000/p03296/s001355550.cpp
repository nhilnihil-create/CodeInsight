#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  int ans = 0;
  for (int i=1; i<N; i++) {
    if (a[i-1]==a[i]) {
      ans++;
      i++;
    }
  }
  cout << ans << endl;
}