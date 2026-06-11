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
  vector<int> C(N-1), S(N-1), F(N-1);
  for (int i=0; i<N-1; i++) cin >> C[i] >> S[i] >> F[i];
  for (int i=0; i<N; i++) {
    int x = 0;
    for (int j=i; j<N-1; j++) {
      if (x<S[j]) x = S[j];
      else if (x%F[j]!=0) x += F[j]-x%F[j];
      x += C[j];
    }
    cout << x << endl;
  }
  return 0;
}