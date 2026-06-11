#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N; scanf("%d", &N);
  vector<int> A(N + 5);
  int most = -INF, most_ix = -1, least = INF, least_ix = -1;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    if (A[i] > most) {
      most_ix = i;
      most = A[i];
    }
    if (A[i] < least) {
      least_ix = i;
      least = A[i];
    }
  }

  vector<pair<int, int>> ans;
  if (least >= 0) {
    for (int i = 1; i < N; ++i) {
      ans.push_back(make_pair(i + 1, i));
    }
  }
  else if (most < 0) {
    for (int i = N; i > 1; --i) {
      ans.push_back(make_pair(i - 1, i));
    }
  }
  else {
    if (abs(least) <= most) {
      for (int i = 1; i <= N; ++i) {
        if (A[i] < 0) {
          ans.push_back(make_pair(i, most_ix));
        }
      }
      // a[i] >= 0
      for (int i = 1; i < N; ++i) {
        ans.push_back(make_pair(i + 1, i));
      }
    }
    else {
      for (int i = 1; i <= N; ++i) {
        if (A[i] > 0) {
          ans.push_back(make_pair(i, least_ix));
        }
      }
      // a[i] < 0
      for (int i = N; i > 1; --i) {
        ans.push_back(make_pair(i - 1, i));
      }
    }
  }

  // check
  // for (pair<int, int> p : ans) {
  //   A[p.first] += A[p.second];
  // }
  // fprintf(stderr, "DEBUG: A=");
  // copy(A.begin() + 1, A.begin() + 1 + N, ostream_iterator<int>(cerr, ", "));
  // fprintf(stderr, "\n");

  int n = ans.size();
  printf("%d\n", n);
  for (pair<int, int> p : ans) {
    printf("%d %d\n", p.second, p.first);
  }
  return 0;
}
