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
	int n, k;
	cin >> n >> k;
	
	vector<ll> x(n), y(n);
	vector<ll> xary, yary;
	rep(i,n){
	cin >> x[i] >> y[i];
		xary.push_back(x[i]);
		yary.push_back(y[i]);
	}
	SORT(xary);
	SORT(yary);

	ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);

	for(ll xi = 0; xi < n; ++xi){
		for(ll xj = xi + 1; xj < n; ++xj){
			for(ll yi = 0; yi < n; ++yi){
				for(ll yj = yi + 1; yj < n; ++yj){
					ll num = 0;
					ll lx = xary[xi], rx = xary[xj];
					ll ly = yary[yi], ry = yary[yj];
					for(ll i = 0; i < n; ++i){
						if(lx <= x[i] && rx >= x[i] && ly <= y[i] && ry >= y[i]) num++;
					}
					if(num >= k) chmin(ans, 1LL* (ry - ly) * (rx - lx));
				}
			}
		}
	}
	cout << ans << endl;
}
