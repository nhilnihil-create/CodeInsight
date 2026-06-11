#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
  	if(n<0) return 0;
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

ll P(ll a, ll b){
    return (a*pow(3LL,b,mod)+b*pow(3LL,b-1,mod))%mod;
}

int main() {
    string S;
    cin >>S;
    ll N = S.size();
    vector<ll> A(N+1,0LL),B(N+1,0LL),C(N+1,0LL),D(N+1,0LL);
    ll a=0,b=0,c=0,d=0;
    rep(i,N){
        if(S[i]=='A') A[i+1] = 1LL;
        if(S[i]=='B') B[i+1] = 1LL;
        if(S[i]=='C') C[i+1] = 1LL;
        if(S[i]=='?') D[i+1] = 1LL; 
    }
    rep(i,N){
        A[i+1] += A[i];
        B[i+1] += B[i];
        C[i+1] += C[i];
        D[i+1] += D[i];
    }
    ll ans = 0LL;
    rep(i,N-1){
        if(S[i]=='B'||S[i]=='?'){
            ans += (P(A[i],D[i]) * P(C[N]-C[i+1],D[N]-D[i+1]))%mod;
            ans %=mod;
        }
    }
    if(ans<0) ans += mod;
    cout<<ans<<endl;
}