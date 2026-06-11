#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int r, d, xtt;
  cin >> r >> d >> xtt;

  int x = xtt;

  rep(i,10) {
    x = r * x - d;
    cout << x << endl;
  }
}

int main() {
  solve();
  return 0;
}