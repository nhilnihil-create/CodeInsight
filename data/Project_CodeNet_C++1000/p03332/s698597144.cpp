#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

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
    ll N,A,B,K;
    cin>>N>>A>>B>>K;
    queue<P> q;
    rep(i,N+1){
        ll t = K - A*i;
        if(t<0) break;
        if(t%B!=0) continue;
        if(t/B>N) continue;
        q.push(make_pair(i,t/B));
    }
    ll ans = 0;
    vector<ll> C(N+1,1LL);
    rep(i,N){
        C[i+1] = (((C[i]*(N-i))%mod)*pow(i+1,mod-2,mod))%mod;
    }
    while(!q.empty()){
        P p = q.front();
        q.pop();
        ans = (ans + C[p.first]*C[p.second])%mod;
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}