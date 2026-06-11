#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (int i = 0; i < (n); ++i)

const int MAX = 2018;
const int INF = 1e9+7;

int N, K, Q;
int A[MAX];

int main() {

  cin >> N >> K >> Q;
  REP (i, N) cin >> A[i];

  vi B(A, A+N);
  sort(B.begin(), B.end());

  vvi lst;
  int ans = INF;

  REP (k, N) {
    int mn = B[k];
    lst = vvi(0);

    int last = -1;
    REP (j, N) {
      if (A[j] < mn) {
        lst.push_back(vi(A+last+1, A+j));
        last = j;
      }
    }
    lst.push_back(vi(A+last+1, A+N));

    vi mxs;
    REP (j, lst.size()) {
      vi v = lst[j];
      sort(v.begin(), v.end());
      REP (i, (int)v.size()-K+1) {
        mxs.push_back(v[i]);
      }
    }

    sort(mxs.begin(), mxs.end());
    if (mxs.size() >= Q) {
      ans = min(ans, mxs[Q-1]-mn);
    }
  }

  cout << ans << endl;

}