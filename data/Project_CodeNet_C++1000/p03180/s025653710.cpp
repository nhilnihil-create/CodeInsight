#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int n;
vector<ll> memo;

ll dp(int now, const vvll &a) {
  //cout << now << endl;
  if(memo[now] != -LINF) {
    return memo[now];
  }

  ll tmp = 0;
  for(int i=0;i<n;++i) {
    for(int j=i+1;j<n;++j) {
      if(((now>>i)&1) && ((now>>j)&1)) {
        tmp += a[i][j];
      }
    }
  }
  ll res = tmp;
  
  for(int t=(now-1)&now;t>0;t=(t-1)&now) {
    res = max(res, dp(t, a) + dp(now^t, a));
  }

  return memo[now] = res;

}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> n;
  vvll a(n, vll(n));
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      cin >> a[i][j];
    }
  }

  memo.resize(1<<n, -LINF);

  cout << dp((1<<n)-1, a) << endl;

  //printv(memo);


}
