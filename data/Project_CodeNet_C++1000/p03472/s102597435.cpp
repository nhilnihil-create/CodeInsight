#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;

int main()
{
  ll N,H;
  cin >> N >> H;
  vector<ll> A(N);
  vector<ll> B(N);
  ll sum=0;
  ll amax=0;
  REP(i, N){
    cin >> A[i] >> B[i];
    amax=max(amax,A[i]);
  }
  sort(ALL(A));
  reverse(ALL(A));
  sort(ALL(B));
  reverse(ALL(B));
  ll cnt = 0;
  REP(i,N){
    if(amax<B[i]){
      sum+=B[i];
      cnt++;
    }
  }
  if(sum<H){
    if((H-sum)%A[0]==0){
      cout << cnt+(H-sum)/A[0] << endl;
    }else{
      cout << cnt+(H-sum)/A[0]+1 << endl;
    }
  }else{
    ll sum2=0;
    REP(i,N){
      sum2+=B[i];
      if(sum2>=H){
        cout << i+1 << endl;
        break;
      }
    }
  }
}