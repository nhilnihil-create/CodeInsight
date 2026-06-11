#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll A,B;
  cin >> A >> B;

  ll x=(A/4+1)*4;
  ll y = B/4*4-1;
  if(x>y){
    ll ans=A;
    FOR(i,A+1,B+1){
      ans^=i;
    }
    cout << ans << endl;
  }else{
    ll ans = A;
    FOR(i,A+1,x){
      ans^=i;
    }
    FOR(i,y+1,B+1){
      ans^=i;
    }
    cout << ans << endl;
  }

}