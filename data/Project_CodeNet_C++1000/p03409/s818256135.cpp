#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int n;
  cin >> n;
  vector<P> B(n), R(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    R[i] = make_pair(b, a);
  }
  rep(j, n) {
    int c, d;
    cin >> c >> d;
    B[j] = make_pair(c, d);
  }
  sort(all(R));
  reverse(all(R));
  sort(all(B));
  vector<int> Mi(n, -1);
  vector<int> Mj(n, -1);
  auto f = [&](int i, int j) {
    return R[i].second < B[j].first
           && R[i].first < B[j].second && Mi[i] < 0
           && Mj[j] < 0;
  };
  rep(i, n) rep(j, n) if(f(i, j)) Mi[i] = j, Mj[j] = i;
  int ans = 0;
  rep(i, n) if(Mi[i] >= 0) ans++;
  cout << ans << endl;
  return 0;
}