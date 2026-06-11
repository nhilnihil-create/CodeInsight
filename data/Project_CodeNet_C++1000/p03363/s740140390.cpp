#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

signed main()
{
	int N;
	cin >> N;
	vector<ll> A(N+1);
	A[0]=0;
	REP(i, N){
		ll a;
		cin >> a;
		A[i+1] = A[i]+a;
	}
	map<ll, ll> mp;
	REP(i, N+1){
		mp[A[i]]++;
	}
	ll ans=0;
	for(auto v : mp){
		ans += v.S*(v.S-1)/2;
	}
	cout << ans << endl;
}
