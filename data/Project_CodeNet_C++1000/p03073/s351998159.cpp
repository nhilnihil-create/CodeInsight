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
  string s;
  cin >> s;
  // s[0] = '0' のとき
  int cnt1 = 0;
  rep(i,s.length()) {
    if (i % 2 != (s[i] - '0')) cnt1++;
  }
  // s[0] = '1' のとき
  int cnt2 = 0;
  rep(i,s.length()) {
    if (i % 2 == (s[i] - '0')) cnt2++;
  }
  cout << min(cnt1, cnt2) << endl;
}

int main() {
  solve();
  return 0;
}