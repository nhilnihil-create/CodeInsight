#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int check(int a, int x) {
  int lb = 1, ub = x+1;
  while(lb+1 < ub) {
    int mb = (lb+ub)/2;
    if((a+mb)*(x+1-mb) > (a+mb-1)*(x+1-mb+1)) lb = mb;
    else ub = mb;
  }
  return lb;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int q;
  cin >> q;
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    int ans = a-1; // (a-i,b+i) (1<=i<=a-1)
    int lb = 0, ub = b;
    while(lb+1 < ub) {
      int mb = (lb+ub)/2;
      int x = check(a, mb);
      if((a+x)*(mb+1-x) < a*b) lb = mb;
      else ub = mb;
    }
    cout << ans+lb << endl;
  }

  return 0;
}
