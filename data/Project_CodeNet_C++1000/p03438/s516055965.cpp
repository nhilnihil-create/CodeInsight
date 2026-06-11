#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  ll d = 0;
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  rep(i, N) {
    if (a[i] < b[i]) d += (b[i] - a[i]) / 2;
    else d -= a[i] - b[i];
  }
  if (d >= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}