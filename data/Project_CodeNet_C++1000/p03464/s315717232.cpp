#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(vector<T> &x) {
	int n = x.size();
	rep(i,n) {
		cout << x[i];
		if (i!=n-1) cout<<" ";
		else cout << endl;
	}
}

template<typename T>
void print(vector<vector<T>> &x) {
	int n = x.size();
	rep(i,n) {
		rep(j,x[i].size()) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct Info {
	ll ins, inb, outs,outb;
	Info(){}
	Info(ll ins, ll inb, ll outs, ll outb): ins(ins),inb(inb),outs(outs),outb(outb){}
};


int main(int argc, char const *argv[]) {
	ll n; cin>>n;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	reverse(a.begin(), a.end());
	vector<Info> dp(n+1);

	auto fail= [](){
		cout << -1 << endl;
		exit(0);
	};

	if (a[0]!=2) fail();

	dp[0] = Info(2,3,2,2);

	for (int i = 1; i < n; ++i) {
		if (a[i] > dp[i-1].inb) fail();
		ll s = (dp[i-1].ins+a[i]-1)/a[i]; s*=a[i];
		ll b = dp[i-1].inb/a[i]; b*=a[i];
		if (s > b) swap(s,b);
		if (s < dp[i-1].ins && dp[i-1].inb < b) fail();
		dp[i] = Info(s,b+a[i]-1,s,b);
		// printf("i = %d, input_smaller = %lld, input_larger = %lld, output_smaller = %lld, output_larger = %lld\n",i,dp[i].ins,dp[i].inb,dp[i].outs,dp[i].outb);
	}
	
	cout << dp[n-1].ins << " " << dp[n-1].inb << endl;
	return 0;
}