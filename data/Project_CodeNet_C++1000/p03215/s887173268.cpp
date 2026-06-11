#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, long long K, vector<long long> a){
	vector<ll> sum(N+1);
	rep(i, N) {
		sum[i+1] = sum[i] + a[i];
	}
	vector<ll> v;
	rep(i, N+1) {
		rep(j, N+1) {
			if (i >= j) continue;
			v.push_back(sum[j]-sum[i]);
			// cout << sum[j]-sum[i] << " ";
		}
	}
	// cout << endl;

	ll res = 0;
	for (ll i = 42; i >= 0; i--) {
		ll now = res + (1LL << i);
		ll cnt = 0;
		// cout << bitset<40>(1LL << i) << endl;
		rep(j, N*(N+1)/2) {
			if ((v[j]&now) == now) cnt++;
		}
		if (cnt >= K) res = now;
		// cout << bitset<40>(res) << endl;
	}

	cout << res << endl;
}

int main(){	
	long long N;
	long long K;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	scanf("%lld",&K);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, K, a);
	return 0;
}

