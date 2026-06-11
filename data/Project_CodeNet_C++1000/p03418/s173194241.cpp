#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define leftunique(a) {sort((a).begin(),(a).end());(a).erase(unique((a).begin(),(a).end()),(a).end());}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

int main()
{
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	For(i,1,n+1){
		int tmp = max(0,i-k);
		ans += tmp * (n / i) + max(0, n%i - k + 1);
	}
	if(k == 0){
		ans -= n;
	}
	cout << ans << endl;
}
