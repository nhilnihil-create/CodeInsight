#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line
#define pb(a) push_back(a)
#define print(x) cout<<x<<endl;
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define m0(x) memset(x,0,sizeof(x))
ll ans[200020];
vector<P> v;
vector<ll>vec[200020]; // 色とその位置
ll color[200020];
vector<ll> C;
ll dp[200020];
const int MOD = 1e9+7;
int main()
{
	ll N;
	cin >> N;
	rep(i,N) cin >> color[i];
	vec[color[0]].pb(1);
	C.pb(color[0]);
	int cnt = 1;
	For(i, 1, N){
		if(color[i] != color[i-1]) {
			cnt ++;
			C.pb(color[i]);
			vec[color[i]].pb(cnt);
			//
		}
	}
	m0(dp);
	dp[0] = 1;
	For(i, 1, cnt + 1) {
		(dp[i] += dp[i-1]) %= MOD;
		auto itr = lb(vec[C[i-1]],i);
		if (itr - vec[C[i-1]].begin() > 0){
			itr --;
			(dp[i] += dp[*itr])%=MOD;
		}
	}
	print(dp[cnt]);
}
