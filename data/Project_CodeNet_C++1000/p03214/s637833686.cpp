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
	vector<int> a(n);
	rep(i, n)cin>>a[i];
	ll sum = 0;
	rep(i,n) sum += a[i];

	ll M = 1e9;
	int ans = -1;
	rep(i,n){
		ll diff = abs(sum - n * a[i]);
		if(M > diff){
			M = diff;
			ans = i;
		}
	}
	cout << ans << endl;
}
