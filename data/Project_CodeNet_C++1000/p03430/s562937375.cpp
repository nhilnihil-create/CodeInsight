#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

char s[353];
int k;

int dp[2][353][353];  // dp[k][l][r] := s[l,r) k modified max pal subseq

int main(){
  scanf("%s%d",s,&k);
  int n = strlen(s);
  REP(i,k+1){
    REP(j,353)REP(k,353)dp[1][j][k] = 0;
    REP(l,n+1){
      REP(lef,n-l+1){
        int rig = lef+l;
        if(l<=1){
          dp[1][lef][rig] = l;
        }else{
          CHMAX(dp[1][lef][rig], dp[1][lef+1][rig-1] + (s[lef]==s[rig-1]?2:0));
          CHMAX(dp[1][lef][rig], dp[1][lef+1][rig]);
          CHMAX(dp[1][lef][rig], dp[1][lef][rig-1]);
          if(i>0)CHMAX(dp[1][lef][rig], dp[0][lef+1][rig-1] + 2);
        }
      }
    }
    // REP(i,n)REP(j,n+1)printf("%d%c",dp[1][i][j],j==n?'\n':' ');puts("");
    REP(j,353)REP(k,353)dp[0][j][k] = dp[1][j][k];
  }
  printf("%d\n",dp[0][0][n]);
  return 0;
}
