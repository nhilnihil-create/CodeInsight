#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;
const string YES = "Yes";
const string NO = "No";

void solve(int N) {
  REP(i, N / 7 + 1)
    if ((N - i * 7) % 4 == 0) {
      cout << YES << endl;
      return;
    }
  cout << NO << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  solve(N);

  return 0;
}
