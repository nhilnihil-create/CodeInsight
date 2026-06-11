#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n)cin>>a[i];
	vector<ll> sum((n*(n+1))/2);
	ll count = 0;
	rep(i,n){
		ll now = a[i];
		sum[count++] = now;
		For(j,i+1,n){
			now+=a[j];
			sum[count++]=now;
		}
	}
	sort(sum.rbegin(),sum.rend());
	ll ans = 0;
	for(ll i = 60; i >= 0; i--){
		ll tmp = 0;
		vector<ll> now(0);
		ll want = pow(2ll,i);
		rep(j,sum.size()){
			if(sum[j] >= want){
				sum[j] -= want;
				now.push_back(sum[j]);
			} 	
		}
		if(now.size() >= k){
			ans += want;
			sum = now;
		}
	}
	cout << ans << endl;
}
