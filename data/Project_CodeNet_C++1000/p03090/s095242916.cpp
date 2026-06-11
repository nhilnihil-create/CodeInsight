#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  ll N;
  cin >> N;
  vector<P> Ans(0);
  int id = 0;
  if (N % 2 == 1) {
    for (int i = 1; i < N; i++) {
      id++;
      Ans.push_back(P(i, N));
    }
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (i == j || i + j == N) continue;
        id++;
        Ans.push_back(P(i, j));
      }
    }
  } else {
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i == j || i + j == N + 1) continue;
        id++;
        Ans.push_back(P(i, j));
      }
    }
  }
  cout << id << endl;
  REP(i, Ans.size()) { cout << Ans[i].first << " " << Ans[i].second << endl; }
}