#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N,Z,W; cin >> N >> Z >> W;
  vector<ll> a(N);
  REP(i,N) cin >> a[i];
  if(N==1){
    cout << abs(a[0]-W) << endl;
    return 0;
  }

  cout << max(abs(a[N-1]-a[N-2]), abs(a[N-1]-W)) << endl;
}
