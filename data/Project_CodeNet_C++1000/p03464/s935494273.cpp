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
	int k;
	cin >> k;
	vector<ll> a(k);
	for(int i = 0; i < k; i++) cin >> a[i];
	ll min_n = 2, max_n = 2;
	for(int i = k - 1; i >= 0; i--) {
		ll min_num = ((min_n + a[i] - 1) / a[i]) * a[i];
		ll max_num = (max_n / a[i]) * a[i] + a[i] - 1;
		if(min_num > max_n || max_num < min_n){
			cout << -1 << endl;
			return 0;
		}
		min_n = min_num;
		max_n = max_num;
	}
	cout << min_n << endl;
	cout << max_n << endl;
}
