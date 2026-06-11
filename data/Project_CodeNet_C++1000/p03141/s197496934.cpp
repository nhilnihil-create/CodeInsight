#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)
#define FOR(i, b, n) for (long i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<long, long>;

void solve(long N, vector<long> A, vector<long> B) {
  // the best strategy is to eat max(Ai + Bi)

  // create Ai + Bi list
  vector<P> ryouri(N);
  REP(i, N)
    ryouri[i] = P(A[i] + B[i], i);

  // sort the list
  sort(ryouri.rbegin(), ryouri.rend());

  // simulate
  ll taka(0), aoki(0);
  REP(i, N)
    if (i % 2)
      aoki += B[ryouri[i].second];
    else
      taka += A[ryouri[i].second];

  // get the answer
  cout << taka - aoki << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;
  vector<long> A(N);
  vector<long> B(N);
  REP(i, N)
    cin >> A[i] >> B[i];

  solve(N, move(A), move(B));

  return 0;
}
