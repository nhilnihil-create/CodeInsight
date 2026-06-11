#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int N, Z, W;
vector<ll> v;

int main(){
  cin >> N >> Z >> W;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  ll ret = abs(W - v[N-1]);
  if(N>=2){
    ret = max(ret, abs(v[N-1] - v[N-2]));
  }

  cout << ret << endl;
  
  return 0;
}