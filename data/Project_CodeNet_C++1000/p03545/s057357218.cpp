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

const int N = 4;

void solve() {
  string s;
  cin >> s;
  rep(bit, (1<<N-1)) {
    int temp = s[0] - '0';
    string ans = s.substr(0, 1);
    rep(i, N-1) {
      if (bit & (1 << i)) {
        temp += (s[i+1] - '0');
        ans = ans + '+' + s[i+1];
      } else {
        temp -= (s[i+1] - '0');
        ans = ans + '-' + s[i+1];
      }
    }
    if (temp == 7) {
      cout << ans + "=7" << endl;
      return;
    }
  }
}

int main() {
  solve();
  return 0;
}