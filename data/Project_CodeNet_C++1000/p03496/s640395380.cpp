#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

int main()
{
  int N; scanf("%d", &N);
  vector<int> A(N + 1);
  int least = INF, most = -INF;
  int ix_most = -1, ix_least = -1;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    if (A[i] > most) {
      ix_most = i;
      most = A[i];
    }
    if (A[i] < least) {
      ix_least = i;
      least = A[i];
    }
  }
  vector<pair<int, int>> ans;
  if (least < 0) {
    if (abs(most) >= abs(least)) {
      for (int i = 1; i < N + 1; ++i) {
        ans.push_back(make_pair(ix_most, i));
      }
      for (int i = 2; i < N + 1; ++i) {
        ans.push_back(make_pair(i - 1, i));
      }
    }
    else {
      for (int i = 1; i < N + 1; ++i) {
        ans.push_back(make_pair(ix_least, i));
      }
      for (int i = N; i > 1; --i) {
        ans.push_back(make_pair(i, i - 1));
      }
    }
  }
  else {
    for (int i = 2; i < N + 1; ++i) {
      ans.push_back(make_pair(i - 1, i));
    }
  }

  // check
  // fprintf(stderr, "DEBUG: ans.size()=%d\n", (int)ans.size());
  // for (int i = 0; i < (int)ans.size(); ++i) {
  //   int x = ans[i].first, y = ans[i].second;
  //   A[y] += A[x];
  // }
  // for (int i = 1; i < N; ++i) {
  //   assert(A[i] <= A[i + 1]);
  // }

  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }

  return 0;
}
