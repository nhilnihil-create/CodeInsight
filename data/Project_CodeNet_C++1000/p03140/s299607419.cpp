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
  string A, B, C;
  cin >> A >> B >> C;
  int ans = 2*N;
  for (int i=0; i<N; i++) {
    if (A[i]==B[i]&&B[i]==C[i]) ans -= 2;
    else if (A[i]==B[i]||B[i]==C[i]||C[i]==A[i]) ans--;
  }
  cout << ans << endl;
}