#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N,K;
  cin >> N >> K;
  ll cnt = 0;
  FOR(i,1,N+1){
    if(i%K==0){
      cnt++;
    }
  }
  ll ans = cnt*cnt*cnt;
  if(K%2==1){
    cout << ans << endl;
  }else{
    ll cnt2 = 0;
    FOR(i,1,N+1){
      if(i%K==K/2){
        cnt2++;
      }
    }
    ans+=cnt2*cnt2*cnt2;
    cout << ans << endl;
  }
}