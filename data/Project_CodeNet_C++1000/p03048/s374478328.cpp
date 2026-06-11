#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  ll ans = 0;
  REP(i,N/R+2){
    REP(j,N/G+2){
      if((N-i*R-j*G)%B==0&&N-i*R-j*G>=0){
        ans++;
      }
    }
  }

  cout << ans << endl;
}