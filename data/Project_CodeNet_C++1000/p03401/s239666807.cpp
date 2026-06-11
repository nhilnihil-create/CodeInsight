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
  ll N;
  cin >> N;

  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> B(N+1);
  B[0] = A[0];
  ll sum = abs(B[0]);
  FOR(i,1,N){
    B[i] = A[i]-A[i-1];
    sum+=abs(B[i]);
  }
  B[N]=A[N-1]*(-1);
  sum+=abs(B[N]);
  REP(i,N){
    ll ans = sum;
    if((B[i]>0 && B[i+1]<0)||(B[i]<0 && B[i+1]>0)){
      ans=sum-min(abs(B[i]),abs(B[i+1]))*2;
    }
    cout << ans << endl;
  }
}