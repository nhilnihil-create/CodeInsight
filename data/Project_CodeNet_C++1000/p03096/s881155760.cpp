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


const int mod = 1e9+7;
int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	map<ll, ll> m, m2;
	rep(i,n) cin >> a[i];
	a.erase(unique(a.begin(),a.end()),a.end());
	n = a.size();
	rep(i,n) m[a[i]] ++;
	vector<ll> dp(n+1,1);
	For(i,1,n+1){
		dp[i] = m2[a[i-1]]+dp[i-1];
		dp[i] %= mod;
		m2[a[i-1]]=dp[i];
	}
	cout << dp[n] << endl;

}
