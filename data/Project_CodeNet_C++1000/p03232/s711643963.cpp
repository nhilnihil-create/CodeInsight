#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;

int n;
ll a[125252];
ll mi[125252];

ll sum[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%lld",a+i);

  mi[1] = 1;
  FOR(i,2,n+1)mi[i] = MOD-mi[MOD%i]*(MOD/i)%MOD;
  
  REP(i,n+1)sum[i+1] = (sum[i] + mi[i+1]) % MOD;

  ll factn = 1;
  FOR(i,1,n+1)factn = factn*i%MOD;
  
  ll ans = 0;
  REP(i,n){
    ans += (sum[i+1] + sum[n-i] - 1) % MOD * factn % MOD * a[i] % MOD;
    ans %= MOD;
  }

  printf("%lld\n",ans);
  return 0;
}
