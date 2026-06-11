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
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> l(n);
	rep(i, n)cin>>l[i];

	ll ans = 1e9;
	for(int mask = 0; mask < (1 << 2 * n); mask++){
		int A = 0, B = 0, C = 0;
		ll tmp = mask;
		int synthetic = 0;
		rep(i,n){
			int now = tmp % 4;
			if(now == 0) ;// not use
			else synthetic++;
			if(now == 1) A += l[i];
			if(now == 2) B += l[i];
			if(now == 3) C += l[i];
			tmp /= 4;
		}
		if(A != 0 && B != 0 && C != 0){
			chmin(ans, (ll)(abs(a-A)+abs(b-B)+abs(c-C)+10*(synthetic-3)));
		}
	}
	cout << ans << endl;
}
