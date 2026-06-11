#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, m, n) for (int i = m; i <= n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main()
{
  cin.tie(0); ios::sync_with_stdio(false);

  int n; cin >> n;

  int sum = 0;
  int a[110];

  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  double average = double(sum) / n;
  double tmp = INF;

  rep(i, n) {
    tmp = min(tmp, abs(average - a[i]) );
  }

  rep(i, n) {
    if( abs(average - a[i]) == tmp ) {
      cout << i << endl;
      return 0;
    }
  }

}