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

  ll ans = 0;
  FOR(i,K+1,N+1){
    ll X = (N-K)/i;
    ans+=(i-K)*X;
    if(N-i*X>=i){
      ans+=i-K;
    }else{
      ans+=N-i*X-K+1;
    }
    if(K==0){
      ans--;
    }
  }

  cout << ans << endl;
}