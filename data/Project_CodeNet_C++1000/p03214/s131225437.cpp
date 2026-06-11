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
  ll N; cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  REP(i,N){
    cin >> a[i];
    sum += a[i];
  }
  ll dist = 1e18;
  ll ans;
  IREP(i,N){
    if(abs(N*a[i]-sum)<=dist){
      dist = abs(N*a[i]-sum);
      ans = i;
    }
  }
  cout << ans << endl;
}