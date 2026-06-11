#include <bits/stdc++.h>
#define INF LLONG_MAX
#define ll  long long
#define ull unsigned long long
#define rep(i,n) for(int i=0; i<n; ++i)
#define MOD 1000000007
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if(a>b) {a=b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if(a<b) {a=b; return true;} return false;}

int main() {
  int N; string A, B, C;
  cin >> N >> A >> B >> C;
  int ans = 0;
  rep(i,N) {
    if(A[i] == B[i] && B[i] == C[i]) continue;
    else if(A[i] == B[i]) ans += 1;
    else if(A[i] == C[i]) ans += 1;
    else if(B[i] == C[i]) ans += 1;
    else ans += 2;
  }
  cout << ans << endl;
}