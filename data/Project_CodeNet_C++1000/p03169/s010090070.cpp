#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

ll N;
double dp[310][310][310];

double rec(ll i, ll j, ll k){
  if(dp[i][j][k]>=0)return dp[i][j][k];
  if(i==0&&j==0&&k==0){
    //cout<<"0 0 0 "<<0.0<<endl;
	return 0.0;
  }
  double res=0.0;
  if(i>0)res+=rec(i-1, j, k)*i;
  if(j>0)res+=rec(i+1, j-1, k)*j;
  if(k>0)res+=rec(i, j+1, k-1)*k;
  res+=N;
  //cout<<res<<endl;
  res*=1.0/(i+j+k);
  //cout<<i<<" "<<j<<" "<<k<<" "<<res<<endl;
  return dp[i][j][k]=res;
}

int main(){
  cin>>N;
  vector<ll> A(N);
  ll one, two, three;
  one=0;two=0; three=0;
  rep(i, N){
    cin>>A[i];
    if(A[i]==1)one++;
    else if(A[i]==2)two++;
    else three++;
  }
  memset(dp, -1, sizeof(dp));

cout<<fixed<<setprecision(10)<<rec(one, two, three)<<endl;

}