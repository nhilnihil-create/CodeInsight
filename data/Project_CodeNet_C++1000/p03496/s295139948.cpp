#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int N; cin >> N;
  vi arr(N);
  rep(i,N) cin >> arr[i];

  cout << 2 * (N-1) << endl;

  int MAX = 0, MIN = 0;
  rep(i,N) {
    if (arr[i] > arr[MAX]) MAX = i;
    if (arr[i] < arr[MIN]) MIN = i;
  }

  if (abs(arr[MAX]) > abs(arr[MIN])) {
    rep(i,2) cout << MAX+1 << ' ' << 2 << endl;
    for (int i=2; i<N; ++i) {
      rep(j,2) cout << i << ' ' << i+1 << endl;
    }
  }
  else {
    rep(i,2) cout << MIN+1 << ' ' << N-1 << endl;
    for (int i=N-1; i>1; --i) {
      rep(j,2) cout << i << ' ' << i-1 << endl;
    }
  }
  return 0;
}
