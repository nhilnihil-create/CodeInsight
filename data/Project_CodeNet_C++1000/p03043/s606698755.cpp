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
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for(int i = 1; i <= n; i++) {
    int temp = i;
    int count = 0;
    while (temp < k) {
      temp *= 2;
      count++;
    }
    ans += pow(0.5, count);
  }
  ans /= n;
  cout << setprecision(10) << ans << endl;
}

int main() {
  solve();
  return 0;
}