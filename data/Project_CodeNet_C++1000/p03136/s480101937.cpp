#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++)
  {
    cin >> L[i];
  }
  sort(L.rbegin(), L.rend());

  int sum = 0;
  for (int i = 1; i < N; i++)
  {
    sum += L[i];
  }
  if (L[0] < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}