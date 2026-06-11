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
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)cin>>a[i];

	vector<ll> left(n+1), right(n+1);
	left[0] = 0;
	right[n] = 0;
	rep(i,n){
		left[i+1] = __gcd(left[i],a[i]);
	}
	for(int i = n; i >= 1; i--){
		right[i-1] = __gcd(right[i],a[i-1]);
	}
	ll ans = 0;
	rep(i,n){
		chmax(ans, __gcd(left[i], right[i+1]));
	}
	cout << ans << endl;
}
