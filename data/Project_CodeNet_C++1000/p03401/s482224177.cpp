#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int n; cin >> n;
  vector<int> a(n+2);
  a[0] = 0;
  REP(i, 1, n) cin >> a[i];
  a[n+1] = 0;

  int sum = 0;
  rep(i, n+1) sum += abs(a[i+1]-a[i]);
  
  REP(i, 1, n){
    int res = sum-abs(a[i+1]-a[i])-abs(a[i]-a[i-1])+abs(a[i+1]-a[i-1]);
    cout << res << endl;
  }

  return 0;
}
