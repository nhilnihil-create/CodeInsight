#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, even = 0;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) {
    if (A[i]%2==0) even++;
  }
  int ans = pow(3, N)-pow(2, even);
  cout << ans << endl;
}