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
	ll x, y;
	cin >> x >> y;
	ll cp = x;
	if(x % y == 0){
		cout << -1 << endl;
		return 0;
	}
	while(x <= 1e18){
		if(x % y != 0){
			cout << x << endl;
			return 0;
		} else {
			x += cp;
		}
	}
	cout << -1 << endl;
}
