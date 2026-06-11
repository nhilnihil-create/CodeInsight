#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// 桁和
int digsum10(int n) {
  int res = 0;
  while (n>0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<int> ans(N-1);
  for (int A=1; A<N; A++) {
    int B = N-A;
    ans[A-1] = digsum10(A)+digsum10(B);
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
}