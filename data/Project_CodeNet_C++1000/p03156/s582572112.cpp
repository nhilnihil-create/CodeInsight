#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(N);
  for (int i=0; i<N; i++) cin >> P[i];
  // 配点が低い順に，グループ1~3を考えてそれぞれの要素数を数える
  int group1=0, group2=0, group3=0;
  for (int i=0; i<N; i++) {
    if (P[i]<=A) group1++;
    else if (B+1<=P[i]) group3++;
    else group2++;
  }
  cout << min(group1, min(group2, group3)) << endl;
}