#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

int main() {
  string S;
  cin>>S;
  int N = S.size();
  vector<ll> A(N+1,0),B(N+1,0),C(N+1,0),D(N+1,0);
  rep(i,N){
    if(S[i]=='A') A[i+1]++;
    if(S[i]=='B') B[i+1]++;
    if(S[i]=='C') C[i+1]++;
    if(S[i]=='?') D[i+1]++;
  }
  rep(i,N) {
    A[i+1] += A[i];
    B[i+1] += B[i];
    C[i+1] += C[i];
    D[i+1] += D[i];
  }
  ll a = pow(3LL,D[N],mod),b=pow(3LL,D[N]-1,mod),c=pow(3LL,D[N]-2,mod),d=pow(3LL,D[N]-3,mod);
  ll ans = 0;
  rep(i,N){
    ll p = 0;
    if(S[i]=='B') {
      p = (p+((A[i]*(C[N]-C[i+1]))%mod*a)%mod)%mod;
      p = (p+((D[i]*(C[N]-C[i+1]))%mod*b)%mod)%mod;
      p = (p+((A[i]*(D[N]-D[i+1]))%mod*b)%mod)%mod;
      p = (p+((D[i]*(D[N]-D[i+1]))%mod*c)%mod)%mod;
    }
    if(S[i]=='?'){
      p = (p+((A[i]*(C[N]-C[i+1]))%mod*b)%mod)%mod;
      p = (p+((D[i]*(C[N]-C[i+1]))%mod*c)%mod)%mod;
      p = (p+((A[i]*(D[N]-D[i+1]))%mod*c)%mod)%mod;
      p = (p+((D[i]*(D[N]-D[i+1]))%mod*d)%mod)%mod;
    }
    ans = (ans+p)%mod;
  }
  cout<<ans<<endl;
}