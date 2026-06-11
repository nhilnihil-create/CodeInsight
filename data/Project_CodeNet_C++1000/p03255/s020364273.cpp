#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll INF = 1e18;

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }
  reverse(ALLOF(v));

  vector<ll> sum(N+1);
  sum[0] = 0;
  rep(i,N){
    sum[i+1] = sum[i] + v[i];
  }

  vector<ll> base;
  {
    ll cnt = 3;
    rep(i,N){
      base.push_back(cnt);
      cnt += 2;
    }
    base[0] = 5;
  }

  ll ret = INF;
  for(int i=1; i<=N; i++){
    ll tmp = (N+i) * (ll)X;
    double dtmp = 0;
    for(int j=0,k=0; j<N; j+=i,k++){
      ll a = sum[(j+i<N?j+i:N)] - sum[j];
      ll b = base[k];
      ll c = a * b;
      tmp += a * b;
      dtmp += a * (double)b;
    }
    if(dtmp > INF) tmp = INF;
    ret = min(ret, tmp);
  }

  cout << ret << endl;
  return 0;
}

